#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

// call seeding() before use rig011 and rig012
void timespec_seeding();
int rig011(int min, int max);
int rig012(int min, int max);

int main(void) {
    timespec_seeding();
	int r_min = -10;
	int r_max = 10;
	long long check_point_count = (long long)r_max - (long long)r_min + 1;
	int rand_int1 = 0;
	int rand_int2 = 0;
	if (r_min<=r_max) {
		for (int i = 0; i < 20; i++ ) {
			printf("%d\n", rig011(r_min,r_max));
		}
		printf("\n");
		for (int i = 0; i < 20; i++ ) {
			printf("%d\n", rig012(r_min,r_max));
		}
	} else {
		printf("Invalid range, min (%d) > max (%d)\n", r_min, r_max);
	}
	printf("\n");
	return 0;
}
void timespec_seeding() {
	struct timespec ts;
	timespec_get(&ts, TIME_UTC);
	srand((unsigned int)(ts.tv_nsec ^ ts.tv_sec)); 
}
int rig011(int min, int max) {
	if (min>max) return 0;
	long long check_point_count = (long long)max - (long long)min + 1;
	long long b1 = (long long)rand();
	long long b2 = (long long)rand();
	return 	(int)((unsigned long long)((b1 << 16) ^ b2) % check_point_count + min);
}
int rig012(int min, int max) {
	if (min>max) return 0;
	long long check_point_count = (long long)max - (long long)min + 1;
	long long x1 = (long long)rand();
	long long x2 = (long long)rand();
	long long x3 = (long long)rand();
	x1 ^= x2 << 13;
	x2 ^= x3 >> 17;
	x3 ^= x1 << 5;
	return (int)((unsigned long long)((x1 << 16) ^ (x2 << 8) ^ x3) % check_point_count + min);
}