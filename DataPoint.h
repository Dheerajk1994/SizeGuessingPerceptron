#ifndef DATA_POINT_H
#define DATA_POINT_H


class DataPoint {

public:
	float x;
	float y;
	int label;

	DataPoint() {
		
	}

	void setData(float xv, float yv) {
		x = xv;
		y = yv;
		label = (x >= y) ? 1 : -1;
	}

};

#endif // !DATA_POINT_H
