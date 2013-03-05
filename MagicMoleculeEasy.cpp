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





#include <sys/time.h>

struct __bench__ {
	double start;
	__bench__() {
		start = sec();
	}
	~__bench__() {
		fprintf(stderr, "%.6f sec\n", sec() - start);
	}
	double sec() {
		struct timeval tv;
		gettimeofday(&tv, NULL);
		return tv.tv_sec + tv.tv_usec * 1e-6;
	}
	operator bool() { return false; }
};

#define benchmark if ( __bench__ __b__ = __bench__()); else





struct node
{
	vector <int> magicPower;
	vector <string> magicBond;
	int power;
	int depth;
};


class MagicMoleculeEasy {
public:
	
	int maxMagicPower( vector <int> magicPower, vector <string> magicBond, int k )
	{
		int max = -1;
		int size = (int)magicPower.size();
		
		
		queue<node> q;
		node n;
		n.magicPower = magicPower;
		n.magicBond = magicBond;
		n.power = 0;
		n.depth = 0;
		
		q.push(n);
		
		__bench__ b;
		
		while( !q.empty() )
		{
			n = q.front();
			q.pop();
			
			if( b.sec() - b.start > 1.5 )
				break;
			
			if( n.depth < k )
			{
				for( int i = 0; i < size; i++ )
				{
					node next = n;
					
					if( next.magicPower[i] != -1 )
					{
						next.power += next.magicPower[i];
						next.magicPower[i] = -1;
						
						for( int x = 0; x < size; x++ )
						{
							if( next.magicBond[i][x] == 'Y' )
								next.magicBond[i][x] = 'y';
							
							if( next.magicBond[x][i] == 'Y' )
								next.magicBond[x][i] = 'y';
						}
						
						next.depth++;
						
						q.push(next);
					}
				}
			}
			else
			{
				bool ok = true;
				
				for( int i = 0; i < size; i++ )
					for( int j = 0; j < size; j++ )
					{
						if( n.magicBond[i][j] == 'Y' )
							ok = false;
					}
				
				
				if( ok == true )
				{
					max = std::max( max, n.power );
				}
				else
				{
					
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
				int magicPower[]          = {1, 2};
				string magicBond[]        = {"NY",
					"YN"};
				int k                     = 1;
				int expected__            = 2;
				
				clock_t start__           = clock();
				int received__            = MagicMoleculeEasy().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])), k);
				return verify_case(casenum, expected__, received__, clock()-start__);
			}
			case 1: {
				int magicPower[]          = {100, 1, 100};
				string magicBond[]        = {"NYN",
					"YNY",
					"NYN"};
				int k                     = 1;
				int expected__            = 1;
				
				clock_t start__           = clock();
				int received__            = MagicMoleculeEasy().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])), k);
				return verify_case(casenum, expected__, received__, clock()-start__);
			}
			case 2: {
				int magicPower[]          = {100, 1, 100};
				string magicBond[]        = {"NYN",
					"YNY",
					"NYN"};
				int k                     = 2;
				int expected__            = 200;
				
				clock_t start__           = clock();
				int received__            = MagicMoleculeEasy().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])), k);
				return verify_case(casenum, expected__, received__, clock()-start__);
			}
			case 3: {
				int magicPower[]          = {4, 7, 5, 8};
				string magicBond[]        = {"NYNY",
					"YNYN",
					"NYNY",
					"YNYN"};
				int k                     = 2;
				int expected__            = 15;
				
				clock_t start__           = clock();
				int received__            = MagicMoleculeEasy().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])), k);
				return verify_case(casenum, expected__, received__, clock()-start__);
			}
			case 4: {
				int magicPower[]          = {46474, 60848, 98282, 58073, 42670, 50373};
				string magicBond[]        = {"NYNNNY", "YNNYNY", "NNNYYY", "NYYNNN", "NNYNNN", "YYYNNN"};
				int k                     = 3;
				int expected__            = 209503;
				
				clock_t start__           = clock();
				int received__            = MagicMoleculeEasy().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])), k);
				return verify_case(casenum, expected__, received__, clock()-start__);
			}
			case 5: {
				int magicPower[]          = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				string magicBond[]        = {"NNYYYNYYNYNNY", "NNYNYYYYYYYNY", "YYNYYNYYYYYYY", "YNYNYYNYYYYYY",
					"YYYYNNYYYYYNY", "NYNYNNYYYYYNN", "YYYNYYNYYYYYY", "YYYYYYYNYNYYY",
					"NYYYYYYYNYYYY", "YYYYYYYNYNNNN", "NYYYYYYYYNNYN", "NNYYNNYYYNYNN", "YYYYYNYYYNNNN"};
				int k                     = 9;
				int expected__            = -1;
				
				clock_t start__           = clock();
				int received__            = MagicMoleculeEasy().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])), k);
				return verify_case(casenum, expected__, received__, clock()-start__);
			}
			case 6: {
				int magicPower[]          = {1, 1};
				string magicBond[]        = {"NN", "NN"};
				int k                     = 1;
				int expected__            = 1;
				
				clock_t start__           = clock();
				int received__            = MagicMoleculeEasy().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])), k);
				return verify_case(casenum, expected__, received__, clock()-start__);
			}
			case 7: {
				int magicPower[]          = {1,1,2,5,2,4,2};
				string magicBond[]        = {"NNNNNNN","NNYNNNN","NYNNNYN","NNNNNNY","NNNNNNN","NNYNNNN","NNNYNNN"};
				int k                     = 3;
				int expected__            = 11;
				
				clock_t start__           = clock();
				int received__            = MagicMoleculeEasy().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])), k);
				return verify_case(casenum, expected__, received__, clock()-start__);
			}
				
				// custom cases
				
				/*      case 8: {
				 int magicPower[]          = ;
				 string magicBond[]        = ;
				 int k                     = ;
				 int expected__            = ;
				 
				 clock_t start__           = clock();
				 int received__            = MagicMoleculeEasy().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])), k);
				 return verify_case(casenum, expected__, received__, clock()-start__);
				 }*/
				/*      case 9: {
				 int magicPower[]          = ;
				 string magicBond[]        = ;
				 int k                     = ;
				 int expected__            = ;
				 
				 clock_t start__           = clock();
				 int received__            = MagicMoleculeEasy().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])), k);
				 return verify_case(casenum, expected__, received__, clock()-start__);
				 }*/
				/*      case 10: {
				 int magicPower[]          = ;
				 string magicBond[]        = ;
				 int k                     = ;
				 int expected__            = ;
				 
				 clock_t start__           = clock();
				 int received__            = MagicMoleculeEasy().maxMagicPower(vector <int>(magicPower, magicPower + (sizeof magicPower / sizeof magicPower[0])), vector <string>(magicBond, magicBond + (sizeof magicBond / sizeof magicBond[0])), k);
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
