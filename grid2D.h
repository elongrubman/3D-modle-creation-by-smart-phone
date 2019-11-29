//
// Created by  Elon Grubman on 23/11/2019.
//

#ifndef NC_RD_FACEMASK_GRID2D_H
#define NC_RD_FACEMASK_GRID2D_H

#include <iostream>
#include <opencv2/opencv.hpp>
#include <tuple>
#include <map>

#define GRID_SIZE 33
#define EDGE_COORDINATE ( GRID_SIZE - 1 ) / 2

using namespace std;
using namespace cv;

class straight_line_equation{
public:
    straight_line_equation(const Matx21f &directionVector, const Matx21f &point) : direction_vector(
            directionVector), point(point) {};

    const Matx21f &getDirectionVector() const {
        return direction_vector;
    }

    void setDirectionVector(const Matx21f &directionVector) {
        direction_vector = directionVector;
    }

    void setPoint(const Matx31f &point) {
        straight_line_equation::point = point;
    }

    const Matx21f &getPoint() const {
        return point;
    }
//    straight_line_equation createStraightLineEquation(Matx21f Pw, Frame& frame){
//        Matx31f Pc = frame.getR() * Pw + frame.getT();
//        Matx31f Pn = Pc * (1/Pc(2,0));
//        Matx31f P0 = -1 * this->grid_ori * ( -1 * this->grid_ori.inv() * this->grid_center_w );
//        Matx31f direction_vector = this->grid_ori * Pn;
//        straight_line_equation created_line (direction_vector, P0);
//        return created_line;
//    }

private:
    Matx21f direction_vector;
    Matx21f point;
};

class voxel{
    float value;
    float confidence;
public:
    voxel(float val=0, float confd=0): value(val), confidence(confd){}
    void setConfidence(float confd){
        confidence = confd;
    }
    void setValue(float val){
        value = val;
    }
    float getConfidence(){
        return confidence;
    }
    float getValue(){
        return value;
    }
};

class grid2D {

    map<tuple<int,int>, voxel> grid;
    float step_size;
    Matx<float, 2, 1> grid_center_w;
public:
    grid2D(float step, Matx21f grid_center_world): step_size(step), grid_center_w(grid_center_world){};

    const Matx21f& getGridCenterW() const {
        return grid_center_w;
    }
};




#endif //NC_RD_FACEMASK_GRID2D_H
