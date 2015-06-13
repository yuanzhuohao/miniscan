#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


void HandleAddress(map<string, string> &mapAddr, string start_addr, string end_addr)
{
	short saddri[4];
	short eaddri[4];
	for (int i = 0, pos = 0; i < 4; i++) {
		pos = start_addr.find(".");
		saddri[i] = atoi(start_addr.substr(0, pos).c_str());
		start_addr = start_addr.substr(pos + 1, start_addr.length());
	}
	for (int i = 0, pos = 0; i < 4; i++) {
		pos = end_addr.find(".");
		eaddri[i] = atoi(end_addr.substr(0, pos).c_str());
		end_addr = end_addr.substr(pos + 1, end_addr.length());
	}


	while (saddri[0] != eaddri[0] || saddri[1] != eaddri[1] || saddri[2] != eaddri[2] || saddri[3] != eaddri[3]) {
		if (saddri[0] == eaddri[0]) {
			if (saddri[1] == eaddri[1]) {
				if (saddri[2] == eaddri[2]) {
					if (saddri[3] == eaddri[3]) {
						break;
					}
					else {
						for (; saddri[3] < eaddri[3]; ++saddri[3]) {
							string str = to_string(saddri[0]) + "." + to_string(saddri[1]) + "." + to_string(saddri[2]) + "." + to_string(saddri[3]);
							mapAddr.insert({ str, str });

						}
					}
				}
				else{
					for (; saddri[2] < eaddri[2]; ++saddri[2]) {
						for (int i = 0; i <= 255; i++){
							string str = to_string(saddri[0]) + "." + to_string(saddri[1]) + "." + to_string(saddri[2]) + "." + to_string(i);
							mapAddr.insert({ str, str });
						}
					}
				}
			}
			else {
				for (; saddri[1] < eaddri[1]; ++saddri[1]) {
					for (int i = 0; i <= 255; ++i) {
						for (int j = 0; j <= 255; ++j) {
							string str = to_string(saddri[0]) + "." + to_string(saddri[1]) + "." + to_string(i) + "." + to_string(j);
							mapAddr.insert({ str, str });
						}
					}
				}
			}
		}
		else {
			for (; saddri[0] < eaddri[0]; ++saddri[0]) {
				for (int i = 0; i <= 255; i++) {
					for (int j = 0; j <= 255; ++j) {
						for (int k = 0; k <= 255; ++k) {
							string str = to_string(saddri[0]) + "." + to_string(i) + "." + to_string(j) + "." + to_string(k);
							mapAddr.insert({ str, str });
						}
					}
				}
			}
		}
	}
	string str = to_string(saddri[0]) + "." + to_string(saddri[1]) + "." + to_string(saddri[2]) + "." + to_string(saddri[3]);
	mapAddr.insert({ str, str });

}