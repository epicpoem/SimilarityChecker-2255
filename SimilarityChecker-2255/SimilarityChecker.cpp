#include <string>
#include <vector>

using namespace std;

class SimilarityChecker {
public:
	explicit SimilarityChecker(const string& question) : question(question) {

	}

	void setQuestionStr(string str) {
		question = str;
	}

	double doCheck(string testStr) {
		double lengthChkScore = doLengthCheck(testStr);
		double alphaChkScore = doAlphaCheck(testStr);
		return lengthChkScore + alphaChkScore;
	}

	double doAlphaCheck(string testStr) {
		
		std::vector<char> TotalCntDic;

		for (char q : question) if (findCh(TotalCntDic, q) == false) TotalCntDic.push_back(q);
		for (char t : testStr) if (findCh(TotalCntDic, t) == false) TotalCntDic.push_back(t);

		std::vector<char> SameCntDic;
		for (char q : question) {
			for (char t : testStr) {
				if (q == t) if (findCh(SameCntDic, q) == false) SameCntDic.push_back(q);
			}
		}

		if (SameCntDic.size() == TotalCntDic.size()) return 40;
		if (SameCntDic.size() == 0) return 0;
		return ( (double)SameCntDic.size() / (double)TotalCntDic.size()) * 40;
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

	bool findCh(vector<char> str, char ch) {
		for (char c : str) {
			if (c == ch) return true;
		}
		return false;
	}
};