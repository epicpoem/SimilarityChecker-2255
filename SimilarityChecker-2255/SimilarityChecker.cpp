#include <string>

using namespace std;

class SimilarityChecker {
public:
	explicit SimilarityChecker(const string& question) : question(question) {

	}

	void setQuestionStr(string str) {
		question = str;
	}

	void doCheck(string testStr) {
		return;
	}

	double doLengthCheck(string testStr) {
		if (question.length() == testStr.length()) return 60;
		if (question.length() >= testStr.length() * 2 ||
			question.length() * 2 <= testStr.length()) return 0;

		int max = std::max(question.length(), testStr.length());
		int min = std::min(question.length(), testStr.length());
		int gap = max-min;

		double ret = (1 - ( (double)gap / (double)min)) * 60;

		return ret;
	}
private:
	string question;
};