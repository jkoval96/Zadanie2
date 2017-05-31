
#include <stdio.h>

void print_line_segment(char ax, char ay, char bx, char by) {
	//using Bresenham's line algorithm
	int dx, dy, D, y, x, i, j, temp1, temp2;
	
	if(ax < bx && ay < by) {
		char field[by+1][bx+1];
		
		for(i = 0; i <= by; i++) {
			for(j = 0; j <= bx; j++) {
				field[i][j] = ' ';
			}
		}
		
		dx = bx - ax;
		dy = by - ay;
		
		if(dx >= dy) {
			D = 2*dy - dx;
			y = by;
		
			for(x = ax; x < bx; x++) {
				field[y][x] = 'x';
				if(D > 0) {
					y = y - 1;
					D = D - 2*dx;
				} else {
					D = D + 2*dy;
				}
			}
		} else {
			D = 2*dx - dy;
			x = ax;
		
			for(y = by; y < ay; y--) {
				field[y][x] = 'x';
				if(D > 0) {
					x = x + 1;
					D = D - 2*dy;
				} else {
					D = D + 2*dx;
				}
			}
		}
		
		for(i = 0; i <= by; i++) {
			for(j = 0; j <= bx; j++) {
				printf("%c", field[i][j]);
			}
			printf("\n");
		}
	} else {
		if(ax > bx && ay > by) {
			temp1 = ax;
			temp2 = ay;
			ax = bx;
			ay = by;
			bx = temp1;
			by = temp2;
		} else if(ax > bx && ay < by) {
			temp1 = ax;
			ax = bx;
			bx = temp1;
		} else if(ax < bx && ay > by) {
			temp2 = ay;
			ay = by;
			by = temp2;
		}
		char field[by+1][bx+1];
		
		for(i = 0; i <= by; i++) {
			for(j = 0; j <= bx; j++) {
				field[i][j] = ' ';
			}
		}
		
		dx = bx - ax;
		dy = by - ay;
		
		if(dx >= dy) {
			D = 2*dy - dx;
			y = ay;
		
			for(x = ax; x < bx; x++) {
				field[y][x] = 'x';
				if(D > 0) {
					y = y + 1;
					D = D - 2*dx;
				} else {
					D = D + 2*dy;
				}
			}
		} else {
			D = 2*dx - dy;
			x = ax;
		
			for(y = ay; y < by; y++) {
				field[y][x] = 'x';
				if(D > 0) {
					x = x + 1;
					D = D - 2*dy;
				} else {
					D = D + 2*dx;
				}
			}
		}
		
		for(i = 0; i <= by; i++) {
			for(j = 0; j <= bx; j++) {
				printf("%c", field[i][j]);
			}
			printf("\n");
		}
	}
}
	
int main(void) {
	int ax, ay, bx, by;
	
	do {
		printf("Zadaj x-ovu a y-ovu suradnicu prveho bodu:\n");	
		scanf("%d %d", &ax, &ay);
	} while((ax < 0 || ax > 255) || (ay < 0 || ay > 255));
		
	do {
		printf("Zadaj x-ovu a y-ovu suradnicu druheho bodu:\n");	
		scanf("%d %d", &bx, &by);
	} while((bx < 0 || bx > 255) || (by < 0 || by > 255));
	
	print_line_segment(ax, ay, bx, by);
	
	return 0;
}
