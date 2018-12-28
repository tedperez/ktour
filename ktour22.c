/**
Name          : ktourXVI.c
Copyright     : none
Author        : ted perez
Created       : 04/22/08 0703
Revised       : 04/10/16 1906
Description   : knight's tour
*/

#include <stdio.h>
#include <time.h>

int Moves[512][4], sq[9][9], depth = 0, maxRows = 0, maxCols = 0, maxDepth = 0;
int nrow = 0, ncol = 0, orow = 0, ocol = 0, i = 0, j = 0, xi = 0, yj = 0, ii = 0, jj = 0, ir = 0, jc = 0;
int currDepth = 0, prevDepth = 0, ctr = 0, ptr = 0, nMoves = 0, startRow = 0, startCol = 0, startNone = 0;
double totnodes = 0, gtnodes = 0, tsf = 0;
time_t start1, start2, start3, stop;
long diff;

int newMoves();
void Occupy();

void Occupy() {

	if (sq[nrow][ncol] == 0) {
		ptr++;
		Moves[ptr][1] = depth;
		Moves[ptr][2] = nrow;
		Moves[ptr][3] = ncol;
		nMoves++;
		totnodes++;
		gtnodes++;
	}
}

int newMoves() {
	/**
	* Check if square not occupied
	*
	*/
	depth++;
	nMoves = 0;
	nrow = orow - 1;
	if (nrow > 0) {
		ncol = ocol + 2;
		if (ncol < maxCols && sq[nrow][ncol] == 0) Occupy();
		ncol = ocol - 2;
		if (ncol > 0 && sq[nrow][ncol] == 0) Occupy();
	}
	nrow = orow + 1;
	if (nrow < maxRows) {
		ncol = ocol + 2;
		if (ncol < maxCols && sq[nrow][ncol] == 0) Occupy();
		ncol = ocol - 2;
		if (ncol > 0 && sq[nrow][ncol] == 0) Occupy();
	}
	ncol = ocol + 1;
	if (ncol < maxCols) {
		nrow = orow - 2;
		if (nrow > 0 && sq[nrow][ncol] == 0) Occupy();
		nrow = orow + 2;
		if (nrow < maxRows && sq[nrow][ncol] == 0) Occupy();
	}
	ncol = ocol - 1;
	if (ncol > 0) {
		nrow = orow - 2;
		if (nrow > 0 && sq[nrow][ncol] == 0) Occupy();
		nrow = orow + 2;
		if (nrow < maxRows && sq[nrow][ncol] == 0) Occupy();
	}
	return nMoves;
}

int main() {
	printf("maxRows (3-8) ? ");
	scanf_s("%d", &maxRows);
	printf("maxCols (3-8) ? ");
	scanf_s("%d", &maxCols);
	printf("\n\n");

	start1 = time(NULL);

	maxDepth = maxRows * maxCols;
	maxRows++;
	maxCols++;
	for (ir = 1; ir < maxRows; ir++) {

		start2 = time(NULL);

		for (jc = 1; jc < maxCols; jc++) {

			int ls = 0;

			ptr = 1;
			Moves[ptr][1] = 1;
			Moves[ptr][2] = ir;
			Moves[ptr][3] = jc;

			depth = 1;

			while (ptr > 0 && Moves[ptr][1] < maxDepth) {
				orow = Moves[ptr][2];
				ocol = Moves[ptr][3];
				sq[orow][ocol] = Moves[ptr][1];

				while (newMoves() > 0) {
					orow = Moves[ptr][2];
					ocol = Moves[ptr][3];
					sq[orow][ocol] = Moves[ptr][1];
				}
				depth--;
				if (depth >= maxDepth) {
					/**
					*  solution found!  display board
					*
					*
					*/
					ls++;  // count solutions only from x,y
					tsf++; // count total solutions found
						   /*
						   printf("\n Solution # %12.0f \n\n", tsf);
						   ii = maxRows - 1;
						   for (xi = ii; xi > 0; xi--) {
						   printf("   ");
						   for (yj = 1; yj < maxCols; yj++) printf("%02d ", sq[xi][yj]);
						   printf("\n\n");
						   }
						   stop = time(NULL);
						   diff = difftime(stop, start);
						   printf("%12.0f nodes in %d seconds.\n\n", totnodes, diff);
						   */
				}
				/**
				* back-track
				*
				*/
				sq[Moves[ptr][2]][Moves[ptr][3]] = 0;
				ptr--;
				while (Moves[ptr][1] != Moves[ptr + 1][1]) {
					sq[Moves[ptr][2]][Moves[ptr][3]] = 0;
					ptr--;
				}
				depth = Moves[ptr][1];
			}

			stop = time(NULL);
			diff = difftime(stop, start2);

			printf("%12d Total solutions from %d,%d found in %7d seconds.  %12.0f nodes tried.\n\n", ls, ir, jc, diff, totnodes);

			totnodes = 0;
			start2 = time(NULL);
		}
	}

	stop = time(NULL);
	diff = difftime(stop, start1);

	printf("%12.0f Total solutions found for a %d x %d board in %d seconds.  %12.0f nodes tried. \n\n", tsf, maxRows - 1, maxCols - 1, diff, gtnodes);
	return 0;
}




