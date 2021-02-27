#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
//index validity check//
void toInd(char a, int b, char a1, int b1, int& r, int& c, int& r1, int& c1) {
	bool valid = true;
	if (b > 9 || b1 > 9) {
		valid = false;
		while (valid == false) {
			cout << "Invalid column number.Enter again" << '\n' << "enter selected column=";
			cin >> b; cout << "Enter destination column="; cin >> b1;
			if (b < 9 && b>0 && b1 > 0 && b1 < 9)valid = true;
		}
	}
	if (b < 9 && b>0 && b1 > 0 && b1 < 9) { c = 8 - b; c1 = 8 - b1; }
	if (a < 97 || a1 < 97 || a>104 || a1>104) {
		valid = false;
		while (valid == false) {
			cout << "Invalid row number.Enter again" << '\n' << "enter selected row=";
			cin >> a; cout << "Enter destination row="; cin >> a1;
			if (a > 96 && a1 > 96 && a < 105 && a1 < 105)valid = true;
		}
	}
	r = a - 97;
	r1 = a1 - 97;
}
//pawn validity check//
bool validPawn(char(&b)[8][8], int r, int c, int r1, int c1, bool& impassant, int& pr, int& pc) {
	bool haa = false;
	int k = 0, k1 = 0;
	if (b[r][c] == 'p' || b[r][c] == 'P') {
		if (b[r][c] == 'p') {

			if ((r == 6) && c == c1 && (r1 == 4 && (b[5][c] == 32 && b[4][c] == 32))) { haa = true; impassant = true; pr = r1; pc = c1; }
			else {

				if (c == c1 && (r1 == 5 && b[5][c] == 32)) {
					haa = true;
				}
				else {
					k = c; k = k + 1;
					k1 = r; k1--;
					if ((c1 == (k) && c != 7) && (b[k1][c1] > 64 && b[k1][c1] < 91)) { haa = true; }
					else {
						k = c; k--;
						k1 = r; k1--;
						if ((c1 == (k) && c != 0) && (b[k1][c1] > 64 && b[k1][c1] < 91)) { haa = true; }
						else {
							k = r; k--;
							if ((r1 != 0 && c == c1 && r1 == k) && b[r1][c] == 32) { haa = true; }
							else {
								k = r; k--;
								if (((r1 == 0 && c == c1 && r1 == k) && b[r1][c] == 32) && r1 == 0) {
									cout << "Enter the promote your pawm" << '\n';
									cin >> b[r][c];
									haa = true;
								}
								else
								{
									k = c; k++;
									k1 = r; k1--;

									if ((r1 == pr - 1 && c1 == pc) && impassant == true && b[r][k] == 80 && b[k1][k] == 32) { haa = true; }
									else
									{
										k = c; k--;
										k1 = r; k1--;
										if ((r1 == pr - 1 && c1 == pc) && impassant == true && b[r][k] == 80 && b[k1][k] == 32) { b[pr][pc] = 32; haa = true; }
									}
								}
							}
						}
					}
				}
			}
		}
		//P for palyer 1 pawn and p for player 2 pawn 
		if (b[r][c] == 'P') {

			if (r == 1 && c == c1 && r1 == 3 && b[2][c] == 32 && b[3][c] == 32) { haa = true; impassant = true; pc = c1; pr = r1; }
			else {
				if (c == c1 && (r1 == 2 && b[c][2] == 32)) {
					haa = true;
				}
				else {
					k = c; k++;
					k1 = r; k1++;
					if ((c1 == (k) && c != 7) && (b[k1][c1] > 96 && b[k1][c1] < 123)) { haa = true; }
					else {
						k = c; k--;
						k1 = r; k1++;
						if ((c1 == (k) && c != 0) && (b[k1][c1] > 96 && b[k1][c1] < 123)) { haa = true; }
						else {
							k = r; k++;
							if ((r1 != 7 && c == c1 && r1 == k) && b[c][r1] == 32) { haa = true; }
							else {
								k = r; k++;
								if (r1 == 7 && c == c1 && r1 == k && b[c][r1] == 32 && r1 == 7) {
									cout << "Enter the promote your pawm" << '\n';
									cin >> b[c][r];
									haa = true;
								}
								else
								{
									k = c; k++;
									k1 = r; k1++;

									if ((r1 == pr - 1 && c1 == pc) && impassant == true && b[r][k] == 80 && b[k1][k] == 32) { haa = true; }
									else
									{
										k = c; k--;
										k1 = r; k1++;
										if (r1 == pr - 1 && c1 == pc && impassant == true && b[r][k] == 112 && b[k1][k] == 32)
										{
											b[pr][pc] = 32;
											haa = true; 
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return haa;
}
// Rook validity function
bool validrook(char(&b)[8][8], int r, int c, int r1, int  c1) {
	bool move = true;
	if (b[r][c] == 'r')
	{
		if (c == c1) {
			if (r1 > r) {
				for (int i = r + 1; i < r1 && move == true; i++)
				{
					if (b[i][c] != 32) { move = false; }
				}
				if (move == true && (b[r1][c1] == 32 || (b[r1][c1] > 64 && b[r1][c1]) < 91)) {
					return true;
				}
			}
			else
			{
				if (r1 < r)for (int i = r - 1; i > r1 && move == true; i--)
				{
					if (b[i][c] != 32) { move = false; }
				}
				if (move == true && (b[r1][c1] == 32 || (b[r1][c1] > 64 && b[r1][c1]) < 91)) {
					return true;
				}
			}
		}
		else {
			if (r == r1) {
				if (c1 > c) {
					for (int i = c - 1; i < c1 && move == true; i++)
					{
						if (b[r][c] != 32) { move = false; }
					}
					if (move == true && (b[r1][c1] == 32 || (b[r1][c1] > 64 && b[r1][c1]) < 91)) {
						return true;
					}
				}
				else
				{
					if (c1 < c) {
						for (int i = c - 1; i > c1 && move == true; i--)
						{
							if (b[r][c] != 32) { move = false; }
						}
						if (move == true && (b[r1][c1] == 32 || (b[r1][c1] > 64 && b[r1][c1]) < 91)) {
							return true;
						}
					}
				}
			}
		}
	}
	else
	{
		if (b[r][c] == 'R') {
			if (c == c1) {
				if (r1 > r) {
					for (int i = r + 1; i < r1 && move == true; i++)
					{
						if (b[i][c] != 32) { move = false; }
					}
					if (move == true && (b[r1][c1] == 32 || (b[r1][c1] > 96 && b[r1][c1]) < 123)) {
						return true;
					}
				}
				else {
					if (r1 < r) {
						for (int i = r - 1; i > r1 && move == true; i--)
						{
							if (b[i][c] != 32) { move = false; }
						}
						if (move == true && (b[r1][c1] == 32 || (b[r1][c1] > 96 && b[r1][c1]) < 123)) {
							return true;
						}
					}
				}
			}
			else {
				if (r == r1) {
					if (c1 > c) {
						for (int i = c + 1; i < c1 && move == true; i++)
						{
							if (b[r][c] != 32) { move = false; }
						}
						if (move == true && (b[r1][c1] == 32 || (b[r1][c1] > 96 && b[r1][c1]) < 123)) {
							return true;
						}
					}
					else
					{
						if (c1 < c)
						{
							for (int i = c - 1; i > c1 && move == true; i--)
							{
								if (b[r][c] != 32) { move = false; }
							}
							if (move == true && (b[r1][c1] == 32 || (b[r1][c1] > 96 && b[r1][c1]) < 123)) {
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}
//Bishp validity
bool validBishp(char(&b)[8][8], int r, int c, int r1, int c1) {
	bool valid = true;
	if (b[r][c] == 'b')
	{
		if (c1 > c && r1 > r) {
			for (int sr = r + 1, sc = c + 1; sr <= r1 && sc <= c1;)
			{
				if (b[sr][sc] != 32 || (b[sr][sc] > 96 && b[sr][sc] < 123)) {
					valid = false; return false;
				}if (sc < 8)sc++;
				if (sr < 8)sr++;
			}
			if (b[r1][c1] == 32 || (91 > b[r1][c1] && b[r1][c1] > 64))return true;
		}
		else
		{
			if (c1 < c && r1 < r) {
				for (int sr = r - 1, sc = c - 1; sr >= r1 && sc >= c1;)
				{
					if (b[sr][sc] != 32 || (b[sr][sc] > 96 && b[sr][sc] < 123)) {
						valid = false; return false;
					}if (sc > 0)sc--;
					if (sr > 0)sr--;
				}
				if (b[r1][c1] == 32 || (91 > b[r1][c1] && b[r1][c1] > 64))return true;
			}
			else
			{
				if (c1 > c && r1 < r) {
					for (int sr = r - 1, sc = c + 1; sr >= r1 && sc <= c1;)
					{
						if (b[sr][sc] != 32 || (b[sr][sc] > 96 && b[sr][sc] < 123))
						{
							valid = false; return false;
						}if (sc < 8)sc++;
						if (sr > 0)sr--;
					}
					if (b[r1][c1] == 32 || (91 > b[r1][c1] && b[r1][c1] > 64))return true;
				}
				else
				{
					if (c1 < c && r1 > r) {
						for (int sr = r + 1, sc = c - 1; sr <= r1 && sc >= c1;)
						{
							if (b[sr][sc] != 32 || (b[sr][sc] > 96 && b[sr][sc] < 123)) {
								valid = false; return false;
							}if (sc > 0)sc--;
							if (sr < 8)sr++;
						}
						if (b[r1][c1] == 32 || (91 > b[r1][c1] && b[r1][c1] > 64))return true;
					}
				}
			}
		}
	}
	else
	{
		if (b[r][c] == 'B') {
			if (c1 > c && r1 > r) {
				for (int sr = r + 1, sc = c + 1; sr <= r1 && sc <= c1;)
				{
					if (b[sr][sc] != 32 || (b[sr][sc] > 64 && b[sr][sc] < 91)) {
						valid = false; return false;
					}if (sc < 8)sc++;
					if (sr < 8)sr++;
				}
				if (b[r1][c1] == 32 || (123 > b[r1][c1] && b[r1][c1] > 96))return true;
			}
			else
			{
				if (c1 < c && r1 < r) {
					for (int sr = r - 1, sc = c - 1; sr >= r1 && sc >= c1;)
					{
						if (b[sr][sc] != 32 || (b[sr][sc] > 64 && b[sr][sc] < 91)) {
							valid = false; return false;
						}if (sc > 0)sc--;
						if (sr > 0)sr--;
					}
					if (b[r1][c1] == 32 || (123 > b[r1][c1] && b[r1][c1] > 96))return true;
				}
				else
				{
					if (c1 > c && r1 < r) {
						for (int sr = r - 1, sc = c + 1; sr >= r1 && sc <= c1;)
						{
							if (b[sr][sc] != 32 || (b[sr][sc] > 64 && b[sr][sc] < 91)) {
								valid = false; return false;
							}if (sc < 8)sc++;
							if (sr > 0)sr--;
						}
						if (b[r1][c1] == 32 || (123 > b[r1][c1] && b[r1][c1] > 96))return true;
					}
					else
					{
						if (c1 < c && r1 > r) {
							for (int sr = r + 1, sc = c - 1; sr <= r1 && sc >= c1;)
							{
								if (b[sr][sc] != 32 || (b[sr][sc] > 64 && b[sr][sc] < 91)) {
									valid = false; return false;
								}if (sc > 0)sc--;
								if (sr < 8)sr++;
							}
							if (b[r1][c1] == 32 || (123 > b[r1][c1] && b[r1][c1] > 96))return true;

						}
					}
				}
			}

		}
	}return false;
}
//Knight validity
bool validKnight(char(&b)[8][8], int r, int c, int  r1, int c1) {
	int k = 0, k1 = 0;
	if (b[r][c] == 'n') {
		k = c; k++;
		k1 = r; k1 -= 2;
		if (c1 == k && r1 == k1 && (b[r1][c1] == 32 || (b[r1][c1] > 64 && b[r1][c1] < 91))) return true;
		else
		{
			k = c; k--;
			k1 = r; k1 -= 2;
			if (c1 == k && r1 == k1 && (b[r1][c1] == 32 || (b[r1][c1] > 64 && b[r1][c1] < 91))) return true;
			else
			{
				k = c; k--;
				k1 = r; k1 += 2;
				if (c1 == k && r1 == k1 && (b[r1][c1] == 32 || (b[r1][c1] > 64 && b[r1][c1] < 91))) return true;
				else
				{
					k = c; k++;
					k1 = r; k1 += 2;
					if (c1 == k && r1 == k1 && (b[r1][c1] == 32 || (b[r1][c1] > 64 && b[r1][c1] < 91))) return true;
					else
					{

						k = c; k += 2;
						k1 = r; k1++;
						if (c1 == k && r1 == k1 && (b[r1][c1] == 32 || (b[r1][c1] > 64 && b[r1][c1] < 91))) return true;
						else {

							k1 = r; k1--;
							k = c; k -= 2;
							if (c1 == k && r1 == k1 && (b[r1][c1] == 32 || (b[r1][c1] > 64 && b[r1][c1] < 91))) return true;
							else {

								k1 = r; k1--;
								k = c; k += 2;
								if (c1 == k && r1 == k1 && (b[r1][c1] == 32 || (b[r1][c1] > 64 && b[r1][c1] < 91))) return true;
								k1 = r; k1++;
								k = c; k -= 2;
								if (c1 == k && r1 == k1 && (b[r1][c1] == 32 || (b[r1][c1] > 64 && b[r1][c1] < 91))) return true;

							}
						}
					}
				}
			}
		}
	}
	else
	{
		if (b[r][c] == 'N') {
			k = c; k++;
			k1 = r; k1 -= 2;
			if (c1 == k && r1 == k1 && (b[r1][c1] == 32 || (b[r1][c1] > 96 && b[r1][c1] < 123))) return true;
			else
			{
				k = c; k--;
				k1 = r; k1 -= 2;
				if (c1 == k && r1 == k1 && (b[r1][c1] == 32 || (b[r1][c1] > 96 && b[r1][c1] < 123))) return true;
				else
				{

					k = c; k--;
					k1 = r; k1++; k1++;
					if (c1 == k && r1 == k1 && (b[r1][c1] == 32 || (b[r1][c1] > 96 && b[r1][c1] < 123))) return true;
					else
					{
						k = c; k++;
						k1 = r; k1 += 2;
						if (c1 == k && r1 == k1 && (b[r1][c1] == 32 || (b[r1][c1] > 96 && b[r1][c1] < 123))) return true;
						else
						{

							k = c; k += 2;
							k1 = r; k1++;
							if (c1 == k && r1 == k1 && (b[r1][c1] == 32 || (b[r1][c1] > 96 && b[r1][c1] < 123))) return true;
							else {

								k1 = r; k1--;
								k = c; k -= 2;
								if (c1 == k && r1 == k1 && (b[r1][c1] == 32 || (b[r1][c1] > 96 && b[r1][c1] < 123))) return true;
								else {

									k1 = r; k1--;
									k = c; k += 2;
									if (c1 == k && r1 == k1 && (b[r1][c1] == 32 || (b[r1][c1] > 96 && b[r1][c1] < 123))) return true;
									k1 = r; k1++;
									k = c; k -= 2;
									if (c1 == k && r1 == k1 && (b[r1][c1] == 32 || (b[r1][c1] > 96 && b[r1][c1] < 123))) return true;

								}
							}

						}
					}
				}
			}
		}
	}
	return false;
}
//Queen validity//
bool validQueen(char(&b)[8][8], int r, int c, int  r1, int c1) {
	bool valid = true;
	if (b[r][c] == 'Q') {
		if (c1 > c && r1 > r) {
			for (int sr = r + 1, sc = c + 1; sr < r1 || sc < c;)
			{
				if (b[sr][sc] != 32) {
					valid = false; return false;
				}
				if (sc < 8)sc++;
				if (sr < 8)sr++;

			}
			if (b[r1][c1] == 32 || (123 > b[r1][c1] && b[r1][c1] > 96))return true;
		}
		else
		{
			if (c1 < c&& r1 < r) {
				for (int sr = r - 1, sc = c - 1; sr > r1 || sc > c1;)
				{
					if (b[sr][sc] != 32) {
						valid = false; return false;
					}
					if (sc > 0)sc--;
					if (sr > 0)sr--;
				}
				if (b[r1][c1] == 32 || (123 > b[r1][c1] && b[r1][c1] > 96))return true;
			}
			else
			{
				if (c1 > c && r1 < r) {
					for (int sr = r - 1, sc = c + 1; sr > r1 || sc < c1;)
					{
						if (b[sr][sc] != 32) {
							valid = false; return false;
						}
						if (sc < 8)sc++;
						if (sr > 0)sr--;
					}
					if (b[r1][c1] == 32 || (123 > b[r1][c1] && b[r1][c1] > 96))return true;
				}
				else
				{
					if (c1 < c && r1 > r) {
						for (int sr = r + 1, sc = c - 1; sr < r1 || sc > c1;)
						{
							if (b[sr][sc] != 32) {
								valid = false; return false;
							}if (sc > 0)sc--;
							if (sr < 8)sr++;
						}
						if (b[r1][c1] == 32 || (123 > b[r1][c1] && b[r1][c1] > 96))return true;

					}
				}
			}
		}bool move = true;
		if (c == c1) {
			if (r1 > r) {
				for (int i = r + 1; i < r1 && move == true; i++)
				{
					if (b[i][c] != 32) { move = false; }
				}
				if (move == true && (b[r1][c] == 32 || (123 > b[r1][c1] && b[r1][c1] > 96))) {
					return true;
				}
			}
			else {
				if (r1 < r) {
					for (int i = r - 1; i > r1 && move == true; i--)
					{
						if (b[i][c] != 32) { move = false; }
					}
					if (move == true && (b[r1][c] == 32 || (123 > b[r1][c1] && b[r1][c1] > 96))) {
						return true;
					}
				}
			}
		}
		else {
			if (r == r1) {
				if (c1 > c) {
					for (int i = c + 1; i < c1 && move == true; i++)
					{
						if (b[r][c] != 32) { move = false; }
					}
					if (move == true && (b[r][c1] == 32 || (b[r1][c1] > 96 && b[r1][c1]) < 123)) {
						return true;
					}
				}
				else
				{
					if (c1 < c)
					{
						for (int i = c - 1; i > c1 && move == true; i--)
						{
							if (b[r][c] != 32) { move = false; }
						}
						if (move == true && (b[r][c1] == 32 || (b[r1][c1] > 96 && b[r1][c1]) < 123)) {
							return true;
						}
					}
				}
			}
		}
	}
	else
	{
		if (b[r][c] == 'q') {
			if (c1 > c && r1 > r) {
				for (int sr = r + 1, sc = c + 1; sr < r1 || sc < c1;)
				{
					if (b[sr][sc] != 32) {
						valid = false; return false;
					}if (sc < 8)sc++;
					if (sr < 8)sr++;
				}
				if (b[r1][c1] == 32 || (91 > b[r1][c1] && b[r1][c1] > 64))return true;
			}
			else
			{
				if (c1 < c&& r1 < r) {
					for (int sr = r - 1, sc = c - 1; sr > r1 || sc > c1;)
					{
						if (b[sr][sc] != 32) {
							valid = false; return false;
						}if (sc > 0)sc--;
						if (sr > 0)sr--;
					}
					if (b[r1][c1] == 32 || (91 > b[r1][c1] && b[r1][c1] > 64))return true;
				}
				else
				{
					if (c1 > c && r1 < r) {
						for (int sr = r - 1, sc = c + 1; sr > r1 || sc < c1;)
						{
							if (b[sr][sc] != 32) {
								valid = false; return false;
							}if (sc < 8)sc++;
							if (sr > 0)sr--;
						}
						if (b[r1][c1] == 32 || (91 > b[r1][c1] && b[r1][c1] > 64))return true;
					}
					else
					{
						if (c1 < c && r1 > r) {
							for (int sr = r + 1, sc = c - 1; sr < r1 || sc > c1;)
							{
								if (b[sr][sc] != 32) {
									valid = false; return false;
								}if (sc > 0)sc--;
								if (sr < 8)sr++;
							}
							if (b[r1][c1] == 32 || (91 > b[r1][c1] && b[r1][c1] > 64))return true;

						}
					}
				}
			}bool move = true;
			if (c == c1) {
				if (r1 > r) {
					for (int i = r + 1; i < r1 && move == true; i++)
					{
						if (b[i][c] != 32) { move = false; }
					}
					if ((move == true) && (b[r1][c] == 32 || (b[r1][c1] > 64 && b[r1][c1]) < 91)) {
						return true;
					}
				}
				else
				{
					if (r1 < r)for (int i = r - 1; i > r1 && move == true; i--)
					{
						if (b[i][c] != 32) { move = false; }
					}
					if ((move == true) && (b[r1][c] == 32 || (b[r1][c1] > 64 && b[r1][c1]) < 91)) {
						return true;
					}
				}
			}
			else {
				if (r == r1) {
					if (c1 > c) {
						for (int i = c + 1; i < c1 && move == true; i++)
						{
							if (b[r][c] != 32) { move = false; }
						}
						if (move == true && (b[r][c1] == 32 || (91 > b[r1][c1] && b[r1][c1] > 64))) {
							return true;
						}
					}
					else
					{
						if (c1 < c) {
							for (int i = c - 1; i > c1 && move == true; i--)
							{
								if (b[r][c] != 32) { move = false; }
							}
							if (move == true && (b[r][c1] == 32 || (91 > b[r1][c1] && b[r1][c1] > 64))) {
								return true;
							}
						}
					}
				}
			}


		}
	}
	return false;
}
//King validity//
bool validKing(char(&b)[8][8], int r, int c, int  r1, int c1) {
	int k = 0, k1 = 0;
	if (b[r][c] == 'k') {
		k = r; k--;
		k1 = c;
		if (r1 == k && c1 == k1 && (b[r1][c1] == 32 || (64 < b[r1][c1] && b[r1][c1] < 91)))return true;
		else
		{
			k = r; k++;
			k1 = c;
			if (r1 == k && c1 == k1 && (b[r1][c1] == 32 || (64 < b[r1][c1] && b[r1][c1] < 91)))return true;
			else
			{
				k = r;
				k1 = c; k1++;
				if (r1 == k && c1 == k1 && (b[r1][c1] == 32 || (64 < b[r1][c1] && b[r1][c1] < 91)))return true;
				else
				{
					k = r;
					k1 = c; k1--;
					if (r1 == k && c1 == k1 && (b[r1][c1] == 32 || (64 < b[r1][c1] && b[r1][c1] < 91)))return true;
					else
					{
						k = r; k--;
						k1 = c; k1++;
						if (r1 == k && c1 == k1 && (b[r1][c1] == 32 || (64 < b[r1][c1] && b[r1][c1] < 91)))return true;
						else
						{
							k = r; k++;
							k1 = c; k1--;
							if (r1 == k && c1 == k1 && (b[r1][c1] == 32 || (64 < b[r1][c1] && b[r1][c1] < 91)))return true;
							else
							{
								k = r; k--;
								k1 = c; k1--;
								if (r1 == k && c1 == k1 && (b[r1][c1] == 32 || (64 < b[r1][c1] && b[r1][c1] < 91)))return true;
								else
								{
									k = r; k++;
									k1 = c; k1++;
									if (r1 == k && c1 == k1 && (b[r1][c1] == 32 || (64 < b[r1][c1] && b[r1][c1] < 91)))return true;
								}
							}
						}
					}

				}
			}
		}
	}
	else
	{
		if (b[r][c] == 'K') {
			k = r; k--;
			k1 = c;
			if (r1 == k && c1 == k1 && (b[r1][c1] == 32 || (96 < b[r1][c1] && b[r1][c1] < 123)))return true;
			else
			{
				k = r; k++;
				k1 = c;
				if (r1 == k && c1 == k1 && (b[r1][c1] == 32 || (96 < b[r1][c1] && b[r1][c1] < 123)))return true;
				else
				{
					k = r;
					k1 = c; k1++;
					if (r1 == k && c1 == k1 && (b[r1][c1] == 32 || (96 < b[r1][c1] && b[r1][c1] < 123)))return true;
					else
					{
						k = r;
						k1 = c; k1--;
						if (r1 == k && c1 == k1 && (b[r1][c1] == 32 || (96 < b[r1][c1] && b[r1][c1] < 123)))return true;
						else
						{
							k = r; k--;
							k1 = c; k1++;
							if (r1 == k && c1 == k1 && (b[r1][c1] == 32 || (96 < b[r1][c1] && b[r1][c1] < 123)))return true;
							else
							{
								k = r; k++;
								k1 = c; k1--;
								if (r1 == k && c1 == k1 && (b[r1][c1] == 32 || (96 < b[r1][c1] && b[r1][c1] < 123)))return true;
								else
								{
									k = r; k--;
									k1 = c; k1--;
									if (r1 == k && c1 == k1 && (b[r1][c1] == 32 || (96 < b[r1][c1] && b[r1][c1] < 123)))return true;
									else
									{
										k = r; k++;
										k1 = c; k1++;
										if (r1 == k && c1 == k1 && (b[r1][c1] == 32 || (96 < b[r1][c1] && b[r1][c1] < 123)))return true;
									}
								}
							}
						}

					}
				}
			}
		}
	}

	return false;
}
//either a movement is possible or not// 
bool validityMove(char(&b)[8][8], int turn, int r, int c, int r1, int c1, bool passant, int pr, int pc) {
	bool move = false;
	if (validPawn(b, r, c, r1, c1, passant, pr, pc)) move = true;
	else
	{
		if (validBishp(b, r, c, r1, c1))move = true;
		else {
			if (validKnight(b, r, c, r1, c1))move = true;
			else {
				if (validQueen(b, r, c, r1, c1))move = true;
				else {
					if (validrook(b, r, c, r1, c1))move = true;
					else {
						if (validBishp(b, r, c, r1, c1))move = true;
						else
						{
							if (validKing(b, r, c, r1, c1))move = true;
						}
					}
				}
			}
		}
	}return move;
}
//King in check or not //
//If return true ... its check
bool check(char(&b)[8][8], int turn, bool& impassant, int& pr, int& pc, int& cgr, int& cgc) {
	int kr = 0, kc = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++) {
			if (turn == 1) {
				if (b[i][j] == 'k') { kr = i; kc = j; }
			}
			if (turn == 2 && b[i][j] == 'K') { kr = i; kc = j; }
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (b[kr][kc] == 'k' && b[i][j] != 32 && b[i][j] > 64 && b[i][j] < 91) {
				if (validPawn(b, i, j, kr, kc, impassant, pr, pc)) { cgr = i; cgr = j; return true; }
				if (validBishp(b, i, j, kr, kc)) { cgr = i; cgr = j; return true; }
				else {
					if (validKnight(b, i, j, kr, kc)) { cgr = i; cgr = j; return true; }
					else {
						if (validQueen(b, i, j, kr, kc)) { cgr = i; cgr = j; return true; }
						else {
							if (validrook(b, i, j, kr, kc)) { cgr = i; cgr = j; return true; }
							else {
								if (validKing(b, i, j, kr, kc)) { cgr = i; cgr = j; return true; }
							}
						}
					}
				}
			}
			else
			{
				if (b[kr][kc] == 'K' && b[i][j] != 32 && b[i][j] > 96 && b[i][j] < 123) {
					if (validPawn(b, i, j, kr, kc, impassant, pr, pc)) { cgr = i; cgr = j; return true; }
					if (validBishp(b, i, j, kr, kc)) { cgr = i; cgr = j; return true; }
					else {
						if (validKnight(b, i, j, kr, kc)) { cgr = i; cgr = j; return true; }
						else {
							if (validQueen(b, i, j, kr, kc)) { cgr = i; cgr = j; return true; }
							else {
								if (validrook(b, i, j, kr, kc)) { cgr = i; cgr = j; return true; }
								else {
									if (validKing(b, i, j, kr, kc)) { cgr = i; cgr = j; return true; }
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}
//Print intitial board set-up
//including pipelining and pipes
void print(char a[8][8]) {
	for (int i = 0; i < 8; i++)
	{
		if (i == 0) {
			cout << setw(6) << 'a' << setw(6) << 'b' << setw(6) << 'c' << setw(6) << 'd'
				<< setw(6) << 'e' << setw(6) << 'f' << setw(6) << 'g' << setw(6) << 'h' << '\n' << '\n' << '\n';
		}
		for (int j = 0; j < 8; j++) {
			if (i == 0 && j == 0) {
				cout << 8 << setw(5) << a[i][j] << '|'; j++;
			}
			else
			{
				if (i == 1 && j == 0) {
					cout << 7 << setw(5) << a[i][j] << '|'; j++;
				}
				else
				{
					if (i == 2 && j == 0) {
						cout << 6 << setw(5) << a[i][j] << '|'; j++;
					}
					else
					{
						if (i == 3 && j == 0) {
							cout << 5 << setw(5) << a[i][j] << '|'; j++;
						}
						else
						{
							if (i == 4 && j == 0) {
								cout << 4 << setw(5) << a[i][j] << '|'; j++;
							}
							else
							{
								if (i == 5 && j == 0) {
									cout << 3 << setw(5) << a[i][j] << '|'; j++;
								}
								else
								{
									if (i == 6 && j == 0) {
										cout << 2 << setw(5) << a[i][j] << '|'; j++;
									}
									else
									{
										if (i == 7 && j == 0) {
											cout << 1 << setw(5) << a[i][j] << '|'; j++;
										}
									}
								}
							}
						}
					}
				}
			}

			cout << setw(5) << a[i][j] << '|';

		}

		if (i == 0) {
			cout << "    " << 8;

		}
		else
		{
			if (i == 1) {
				cout << "    " << 7;
			}
			else
			{
				if (i == 2) {
					cout << "    " << 6;
				}
				else
				{
					if (i == 3) {
						cout << "    " << 5;
					}
					else
					{
						if (i == 4) {
							cout << "    " << 4;
						}
						else
						{
							if (i == 5) {
								cout << "    " << 3;
							}
							else
							{
								if (i == 6) {
									cout << "    " << 2;
								}
								else
								{
									if (i == 7) {
										cout << "    " << 1;
									}
								}
							}
						}
					}
				}
			}
		}

		cout << '\n';
		for (int i = 0; i < 45; i++)
		{
			if (i == 0)cout << "   ";
			cout << '-';
		}
		cout << '\n';
		if (i == 7) {

			cout << '\n' << setw(6) << 'a' << setw(6) << 'b' << setw(6) << 'c' << setw(6) << 'd' << setw(6) << 'e'
				<< setw(6) << 'f' << setw(6) << 'g' << setw(6) << 'h' << '\n';
		}
	}
}
//cordinate validity
void validityCord(char(&b)[8][8], int turn, int& r, int& c, int& r1, int& c1) {
	bool valid = true;
	char a, a1;
	int j, j1;
	if (turn == 1 && (b[r][c] > 64 && b[r][c] < 91)) {
		valid = false;
		while (valid == false) {
			cout << "selected peice is not yours.select again" << endl;
			cin >> a >> j >> a1 >> j1;
			toInd(a, j, a1, j1, c, r, c1, r1);
			if (b[r][c] > 96 && b[r][c] < 123)valid = true;
		}
	}
	if (turn == 2 && b[r][c] > 96 && b[r][c] < 123) {
		valid = false;
		while (valid == false) {
			cout << "selected peice is not yours.select again" << endl;
			cin >> a >> j >> a1 >> j1;
			toInd(a, j, a1, j1, c, r, c1, r1);
			if (b[r][c] > 64 && b[r][c] < 91)valid = true;
		}
	}

}
int main() {
	char bf[8][8];
	//this is to hard code board array to test the case
	char b[8][8] = { 'R','N','B','Q','K','B','N','R',
					 'P','P','P','P','P','P','P','P',
					  32, 32,32, 32, 32, 32, 32, 32,
					 32, 32, 32, 32, 32, 32, 32, 32,
					 32, 32, 32, 32, 32, 32, 32, 32,
					 32, 32, 32, 32, 32, 32, 32, 32,
					 'p','p','p','p','p','p','p','p',
					 'r','n','b','q','k','b','n','r' };
	memcpy(bf, b, 8 * 8);//copy 2D array
	bool move = false, king = false;
	int turn = 1, j = 0, j1 = 0, kr = 0, kc = 0, r, c, r1, c1, cgr, cgc;
	char a = 32, a1 = 32;
	bool passant = false, valid = true;//passant=true if move occured is impassant
	int pr = -1, pc = -1;
	while (king == false) {// loop continues till game ends
		print(b);
		cin >> a >> j >> a1 >> j1;
		toInd(a, j, a1, j1, c, r, c1, r1);
		validityCord(b, turn, r, c, r1, c1);
		move = validityMove(b, turn, r, c, r1, c1, passant, pr, pc);
		if (move == true) {
			char pAlph = b[r][c];
			char mKill = b[r1][c1];
			bf[r1][c1] = b[r][c];
			bf[r][c] = 32;
			bool danger = check(b, turn, passant, pr, pc, cgr, cgc);
			if (danger == true) {
				cout << "its a check" << '\n';
				bf[r][c] = pAlph;
				bf[r1][c1] = mKill;
				while (danger == true) {
					cout << "enter cordinates again:" << '\n';
					cin >> a >> j >> a1 >> j1;
					toInd(a, j, a1, j1, c, r, c1, r1);
					validityCord(b, turn, r, c, r1, c1);
					char pAlph = b[r][c];
					char mKill = b[r1][c1];
					b[r1][c1] = b[r][c];
					b[r][c] = 32;
					move = validityMove(b, turn, r, c, r1, c1, passant, pr, pc);
					danger = check(b, turn, passant, pr, pc, cgr, cgc);
					if (danger == true) {
						b[r][c] = pAlph;
						b[r1][c1] = mKill;
					}
				}

				b[r1][c1] = b[r][c];
				b[r][c] = 32;
			}
		}
		else
		{
			b[r1][c1] = b[r][c];
			b[r][c] = 32;
		}
		turn = (turn % 2) + 1;
		move = false;
		system("cls");
	}
	system("pause");
	return 0;
}