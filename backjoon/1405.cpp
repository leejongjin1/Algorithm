#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int n;
bool arr[100][100];
double d[4]; // 동, 서, 남, 북
double ret;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void dfs(int y, int x, int cnt, double p)
{
	if (cnt == n)
	{
		ret += p;
		return;
	}

	int ny, nx;
	for (int i = 0; i < 4; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if (arr[ny][nx] == 0)
		{
			arr[ny][nx] = 1;
			dfs(ny, nx, cnt + 1, p * d[i]);
			arr[ny][nx] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < 4; i++)
	{
		cin >> d[i];
		d[i] /= 100;
	}

	arr[50][50] = 1;
	dfs(50, 50, 0, 1);

	// 소수점 11자리까지 출력
	cout.precision(11);
	cout.fixed;

	cout << ret << '\n';

	return 0;
}
