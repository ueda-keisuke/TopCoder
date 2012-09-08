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


class XorBoardDivTwo {
public:

    void flip( int x, int y, vector<string> &board )
    {
        // row
        for( int j = 0; j < board[x].length(); j++ )
        {
            if( board[x][j] == '0' )
                board[x][j] = '1';
            else
                board[x][j] = '0';
        }

        for( int j = 0; j < board.size(); j++ )
        {
            if( board[j][y] == '0' )
                board[j][y] = '1';
            else
                board[j][y] = '0';
        }
        
    }
    
	int theMax( vector <string> board )
	{
        int max = 0;
        
        for( int x = 0; x < board.size(); x++ )
        {
            for( int y = 0; y < board[x].length(); y++ )
            {
                vector<string> copy = board;
                flip( x, y, copy );
                
                int count = 0;
                for( int i = 0; i < copy.size(); i++ )
                {
                    for( int j = 0; j < copy[i].length(); j++ )
                    {
                        if( copy[i][j] == '1' )
                            count++;
                    }
                }
                
                max = std::max( max, count );
            }
        }
        

        
		return max;
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
                string board[]            = {"101",
                    "010",
                    "101"};
                int expected__            = 9;
                
                clock_t start__           = clock();
                int received__            = XorBoardDivTwo().theMax(vector <string>(board, board + (sizeof board / sizeof board[0])));
                return verify_case(casenum, expected__, received__, clock()-start__);
            }
            case 1: {
                string board[]            = {"111",
                    "111",
                    "111"};
                int expected__            = 5;
                
                clock_t start__           = clock();
                int received__            = XorBoardDivTwo().theMax(vector <string>(board, board + (sizeof board / sizeof board[0])));
                return verify_case(casenum, expected__, received__, clock()-start__);
            }
            case 2: {
                string board[]            = {"0101001",
                    "1101011"};
                int expected__            = 9;
                
                clock_t start__           = clock();
                int received__            = XorBoardDivTwo().theMax(vector <string>(board, board + (sizeof board / sizeof board[0])));
                return verify_case(casenum, expected__, received__, clock()-start__);
            }
            case 3: {
                string board[]            = {"000",
                    "001",
                    "010",
                    "011",
                    "100",
                    "101",
                    "110",
                    "111"};
                int expected__            = 15;
                
                clock_t start__           = clock();
                int received__            = XorBoardDivTwo().theMax(vector <string>(board, board + (sizeof board / sizeof board[0])));
                return verify_case(casenum, expected__, received__, clock()-start__);
            }
            case 4: {
                string board[]            = {"000000000000000000000000",
                    "011111100111111001111110",
                    "010000000100000001000000",
                    "010000000100000001000000",
                    "010000000100000001000000",
                    "011111100111111001111110",
                    "000000100000001000000010",
                    "000000100000001000000010",
                    "000000100000001000000010",
                    "011111100111111001111110",
                    "000000000000000000000000"}
                ;
                int expected__            = 105;
                
                clock_t start__           = clock();
                int received__            = XorBoardDivTwo().theMax(vector <string>(board, board + (sizeof board / sizeof board[0])));
                return verify_case(casenum, expected__, received__, clock()-start__);
            }
                
                // custom cases
                
                /*      case 5: {
                 string board[]            = ;
                 int expected__            = ;
                 
                 clock_t start__           = clock();
                 int received__            = XorBoardDivTwo().theMax(vector <string>(board, board + (sizeof board / sizeof board[0])));
                 return verify_case(casenum, expected__, received__, clock()-start__);
                 }*/
                /*      case 6: {
                 string board[]            = ;
                 int expected__            = ;
                 
                 clock_t start__           = clock();
                 int received__            = XorBoardDivTwo().theMax(vector <string>(board, board + (sizeof board / sizeof board[0])));
                 return verify_case(casenum, expected__, received__, clock()-start__);
                 }*/
                /*      case 7: {
                 string board[]            = ;
                 int expected__            = ;
                 
                 clock_t start__           = clock();
                 int received__            = XorBoardDivTwo().theMax(vector <string>(board, board + (sizeof board / sizeof board[0])));
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
