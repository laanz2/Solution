// Rectangle.h
#ifndef RECTANGLE_H
#define RECTANGLE_H

class CRectangle {
private:
    int width;
    int height;
public:
    // Constructor
    CRectangle() {
        width = 0;
        height = 0;
    }

    // Destructor
    ~CRectangle() {}

    // Getter for width
    int getWidth() const {
        return width;
    }

    // Setter for width
    void setWidth(int w) {
        width = w;
    }

    // Getter for height
    int getHeight() const {
        return height;
    }

    // Setter for height
    void setHeight(int h) {
        height = h;
    }

    // Method to calculate area
    int area() const {
        return width * height;
    }
};

#endif

