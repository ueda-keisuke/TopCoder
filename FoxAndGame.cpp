#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;


class FoxAndGame {
public:
	int countStars( vector <string> result )
	{
		int stars = 0;
		
		for( int i = 0; i < result.size(); i++ )
			for( int j = 0; j < result[i].length(); j++ )
			{
				if( result[i][j] == 'o' )
					stars++;
			}
		
		
		return stars;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) {
		cerr << "Example " << casenum << "... ";
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl;
			cerr << "    Received: " << received << endl;
		}
		
		return verdict == "PASSED";
	}
	
	int run_test_case(int casenum) {
		switch (casenum) {
			case 0: {
				string result[]           = {"ooo",
					"ooo"};
				int expected__            = 6;
				
				clock_t start__           = clock();
				int received__            = FoxAndGame().countStars(vector <string>(result, result + (sizeof result / sizeof result[0])));
				return verify_case(casenum, expected__, received__, clock()-start__);
			}
			case 1: {
				string result[]           = {"ooo",
					"oo-",
					"o--"};
				int expected__            = 6;
				
				clock_t start__           = clock();
				int received__            = FoxAndGame().countStars(vector <string>(result, result + (sizeof result / sizeof result[0])));
				return verify_case(casenum, expected__, received__, clock()-start__);
			}
			case 2: {
				string result[]           = {"ooo",
					"---",
					"oo-",
					"---",
					"o--"};
				int expected__            = 6;
				
				clock_t start__           = clock();
				int received__            = FoxAndGame().countStars(vector <string>(result, result + (sizeof result / sizeof result[0])));
				return verify_case(casenum, expected__, received__, clock()-start__);
			}
			case 3: {
				string result[]           = {"o--",
					"o--",
					"o--",
					"ooo",
					"---"};
				int expected__            = 6;
				
				clock_t start__           = clock();
				int received__            = FoxAndGame().countStars(vector <string>(result, result + (sizeof result / sizeof result[0])));
				return verify_case(casenum, expected__, received__, clock()-start__);
			}
			case 4: {
				string result[]           = {"---",
					"o--",
					"oo-",
					"ooo",
					"ooo",
					"oo-",
					"o--",
					"---"};
				int expected__            = 12;
				
				clock_t start__           = clock();
				int received__            = FoxAndGame().countStars(vector <string>(result, result + (sizeof result / sizeof result[0])));
				return verify_case(casenum, expected__, received__, clock()-start__);
			}
			case 5: {
				string result[]           = {"---",
					"---",
					"---",
					"---",
					"---",
					"---"};
				int expected__            = 0;
				
				clock_t start__           = clock();
				int received__            = FoxAndGame().countStars(vector <string>(result, result + (sizeof result / sizeof result[0])));
				return verify_case(casenum, expected__, received__, clock()-start__);
			}
			case 6: {
				string result[]           = {"oo-"};
				int expected__            = 2;
				
				clock_t start__           = clock();
				int received__            = FoxAndGame().countStars(vector <string>(result, result + (sizeof result / sizeof result[0])));
				return verify_case(casenum, expected__, received__, clock()-start__);
			}
				
				// custom cases
				
				/*      case 7: {
				 string result[]           = ;
				 int expected__            = ;
				 
				 clock_t start__           = clock();
				 int received__            = FoxAndGame().countStars(vector <string>(result, result + (sizeof result / sizeof result[0])));
				 return verify_case(casenum, expected__, received__, clock()-start__);
				 }*/
				/*      case 8: {
				 string result[]           = ;
				 int expected__            = ;
				 
				 clock_t start__           = clock();
				 int received__            = FoxAndGame().countStars(vector <string>(result, result + (sizeof result / sizeof result[0])));
				 return verify_case(casenum, expected__, received__, clock()-start__);
				 }*/
				/*      case 9: {
				 string result[]           = ;
				 int expected__            = ;
				 
				 clock_t start__           = clock();
				 int received__            = FoxAndGame().countStars(vector <string>(result, result + (sizeof result / sizeof result[0])));
				 return verify_case(casenum, expected__, received__, clock()-start__);
				 }*/
			default:
				return -1;
		}
	}
}


int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
