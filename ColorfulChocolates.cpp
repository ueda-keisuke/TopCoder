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
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;


class ColorfulChocolates {
public:
	int maximumSpread( string chocolates, int maxSwaps )
	{
        int max = 0;
        set<char> colors( chocolates.begin(), chocolates.end() );
                
        for( set<char>::iterator it = colors.begin(); it != colors.end(); it++ )
        {
            for( int i = 0; i < chocolates.length(); i++ )
            {
                if( chocolates[i] == *it )
                {
                    int left = i - 1;
                    int right = i + 1;
                    
                    while( chocolates[left] == *it ) left--;
                    while( chocolates[right] == *it ) right++;
                    
                    string c = chocolates;
                    int swap = maxSwaps;
                    
                    int d = 1;
                    while( d < c.length() )
                    {
                        if( left - d >= 0 && c[left - d] == *it && swap >= d )
                        {
                            c[left - d] = '.';
                            c[left] = *it;
                            swap -= d;
                            left--;
                            d = 1;
                            continue;
                        }

                        if( right + d < c.length() && c[right + d] == *it && swap >= d )
                        {
                            c[right + d] = '.';
                            c[right] = *it;
                            swap -= d;
                            right++;
                            d = 1;
                            continue;
                        }
                        
                        d++;
                    }
                    
                    int spread = 0;
                    for( int j = 0; j < c.length(); j++ )
                    {
                        if( c[j] == *it )
                        {
                            spread++;
                            max = std::max( spread, max );
                        }
                        else
                            spread = 0;
                    }
                }
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
                string chocolates         = "ECDFFABAFEAEBBFABAABEDAFFBCCDABBAEEACFEFBFEAEBBDBB";
                int maxSwaps              = 126;
                int expected__            = 13;
                
                clock_t start__           = clock();
                int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
                return verify_case(casenum, expected__, received__, clock()-start__);
            }
            case 1: {
                string chocolates         = "BAAABBCCDDDDCDDAACADBCCBDDDCCDDDADABACADCDDADCADAA";
                int maxSwaps              = 113;
                int expected__            = 19;
                
                clock_t start__           = clock();
                int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
                return verify_case(casenum, expected__, received__, clock()-start__);
            }
            case 2: {
                string chocolates         = "ABBABABBA";
                int maxSwaps              = 3;
                int expected__            = 4;
                
                clock_t start__           = clock();
                int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
                return verify_case(casenum, expected__, received__, clock()-start__);
            }
            case 3: {
                string chocolates         = "ABBABABBA";
                int maxSwaps              = 4;
                int expected__            = 5;
                
                clock_t start__           = clock();
                int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
                return verify_case(casenum, expected__, received__, clock()-start__);
            }
            case 4: {
                string chocolates         = "QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO";
                int maxSwaps              = 77;
                int expected__            = 5;
                
                clock_t start__           = clock();
                int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
                return verify_case(casenum, expected__, received__, clock()-start__);
            }
                
                // custom cases
                
                /*      case 5: {
                 string chocolates         = ;
                 int maxSwaps              = ;
                 int expected__            = ;
                 
                 clock_t start__           = clock();
                 int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
                 return verify_case(casenum, expected__, received__, clock()-start__);
                 }*/
                /*      case 6: {
                 string chocolates         = ;
                 int maxSwaps              = ;
                 int expected__            = ;
                 
                 clock_t start__           = clock();
                 int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
                 return verify_case(casenum, expected__, received__, clock()-start__);
                 }*/
                /*      case 7: {
                 string chocolates         = ;
                 int maxSwaps              = ;
                 int expected__            = ;
                 
                 clock_t start__           = clock();
                 int received__            = ColorfulChocolates().maximumSpread(chocolates, maxSwaps);
                 return verify_case(casenum, expected__, received__, clock()-start__);
                 }*/
            default:
                return -1;
		}
	}
}


int main(int argc, char *argv[]) {
//    moj_harness::run_test(3);
//    return 0;
    
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
