#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <sys/time.h>
#include <unistd.h>
#include <ctime>
using namespace std;
using std::vector;
using std::chrono::microseconds;


#define H 720
#define W 1280
#define FPS 30

int main() {
	vector<vector<int>> frame(H, vector<int>(W, rand() % 100));
//	auto milli_sec = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
//	while (true) {
		//std::sleep_for(std::chrono::microseconds(16));
		usleep(32);
		int f = 0;	
		for(auto i : frame) {
			f++;	
			for (auto j : i)
				cout << j << " ";
			cout<<endl;
		}
//	}
	
	return 0;
}
