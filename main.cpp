#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	cin >> t;
	while (0 < (t--))
	{
		string s;
		cin >> s;
		int n;
		cin >> n;
		string list;
		cin >> list;

		auto oss = ostringstream{};
		auto glist = vi{};
		glist.reserve(n);
		for (const auto& c : list) {
			if ('[' == c) {
				continue;
			}

			if (',' == c || ']' == c) {
				auto iss = istringstream{ oss.str() };
				int x;
				iss >> x;

				glist.push_back(x);

				oss = ostringstream{};

				continue;
			}

			oss << c;
		}

		auto head = int{ 0 };
		auto tail = int{ n - 1 };
		auto direction = bool{ false };
		auto ct = int{ n };
		auto hasError = bool{ false };
		for (const auto& q : s) {
			if ('R' == q) {
				direction ^= true;
			}
			else if ('D' == q) {
				if (0 < ct) {
					if (!direction) {
						++head;
					}
					else {
						--tail;
					}

					--ct;
				}
				else {
					hasError = true;
					cout << "error";
					break;
				}
			}
		}

		if (!hasError) {
			cout << '[';
			if (!direction) {
				for (auto i = head; i < tail; ++i) {
					cout << glist[i] << ',';
				}

				if (head <= tail) {
					cout << glist[tail] << ']';
				}
				else {
					cout << ']';
				}
			}
			else {
				for (auto i = tail; head < i; --i) {
					cout << glist[i] << ',';
				}
				if (head <= tail) {
					cout << glist[head] << ']';
				}
				else {
					cout << ']';
				}
			}
		}

		cout << '\n';
	}

	return 0;
}