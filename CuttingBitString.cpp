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



struct node
{
    int depth;
    string s;
};



class CuttingBitString {
public:
	int getmin( string S )
	{
        string five[] =
        {
            "1101100011010111001001101011011100010111011110101",
            "10101101011110001110101111000101101011000110001",
            "100010101100011100100011000001001000100111101",
            "110111100000101101101011001110100111011001",
            "1011000110100010101111000010111011000101",
            "10001110000110111100100110111111000001",
            "11100011010111111010100100110001101",
            "101101011110011000100000111101001",
            "1001000110000100111001110010101",
            "1110100011010100101001010001",
            "10111010010000111011011101",
            "100101010000001011111001",
            "111011100110101100101",
            "1011111010111100001",
            "10011000100101101",
            "11110100001001",
            "110000110101",
            "1001110001",
            "1111101",
            "11001",
            "101",
            "1"
        };
        size_t size = sizeof(five)/sizeof(string);
        
        
        node n;
        n.depth = 0;
        n.s = S;
        stack<node> s;
        s.push(n);
        
        int min = 99999;
        
        while( !s.empty() )
        {
            n = s.top();
            s.pop();
            
            if( n.s.empty() )
                min = std::min( n.depth, min );
            
            for( int i = 0; i < size; i++ )
            {
                if( five[i].length() <= n.s.length() )
                {
                    bool flag = true;
                    
                    for( int j = 0; j < five[i].length(); j++ )
                    {
                        if( five[i][j] != n.s[j] )
                        {
                            flag = false;
                            break;
                        }
                    }
                    
                    // match
                    if( flag == true )
                    {
                        node next;
                        next.s = n.s.substr( five[i].length() );
                        next.depth = n.depth + 1;
                        
                        s.push(next);
                    }
                }
            }
        }
        
        if( min == 99999 )
            return -1;
        
        return min;
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
                string S                  = "101101101";
                int expected__            = 3;
                
                clock_t start__           = clock();
                int received__            = CuttingBitString().getmin(S);
                return verify_case(casenum, expected__, received__, clock()-start__);
            }
            case 1: {
                string S                  = "1111101";
                int expected__            = 1;
                
                clock_t start__           = clock();
                int received__            = CuttingBitString().getmin(S);
                return verify_case(casenum, expected__, received__, clock()-start__);
            }
            case 2: {
                string S                  = "00000";
                int expected__            = -1;
                
                clock_t start__           = clock();
                int received__            = CuttingBitString().getmin(S);
                return verify_case(casenum, expected__, received__, clock()-start__);
            }
            case 3: {
                string S                  = "110011011";
                int expected__            = 3;
                
                clock_t start__           = clock();
                int received__            = CuttingBitString().getmin(S);
                return verify_case(casenum, expected__, received__, clock()-start__);
            }
            case 4: {
                string S                  = "1000101011";
                int expected__            = -1;
                
                clock_t start__           = clock();
                int received__            = CuttingBitString().getmin(S);
                return verify_case(casenum, expected__, received__, clock()-start__);
            }
            case 5: {
                string S                  = "111011100110101100101110111";
                int expected__            = 5;
                
                clock_t start__           = clock();
                int received__            = CuttingBitString().getmin(S);
                return verify_case(casenum, expected__, received__, clock()-start__);
            }
                
                // custom cases
                
                /*      case 6: {
                 string S                  = ;
                 int expected__            = ;
                 
                 clock_t start__           = clock();
                 int received__            = CuttingBitString().getmin(S);
                 return verify_case(casenum, expected__, received__, clock()-start__);
                 }*/
                /*      case 7: {
                 string S                  = ;
                 int expected__            = ;
                 
                 clock_t start__           = clock();
                 int received__            = CuttingBitString().getmin(S);
                 return verify_case(casenum, expected__, received__, clock()-start__);
                 }*/
                /*      case 8: {
                 string S                  = ;
                 int expected__            = ;
                 
                 clock_t start__           = clock();
                 int received__            = CuttingBitString().getmin(S);
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
