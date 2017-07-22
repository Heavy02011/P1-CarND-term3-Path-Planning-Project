// class holding all relevant data for traffic around us. based on lesson 4.16 (vehicle.h) and 5.30 (helpers.py). assuming constant velocities!

#ifndef VEHICLE_H
#define VEHICLE_H
#include <math.h>

using namespace std;

class Vehicle
{
public:
  
  Vehicle(int id, double x, double y, double vx, double vy, double s, double d, double a, double d_dot, double d_double_dot) { 
    
    this->id = id;
    this->x  = x; 
    this->y  = y; 
    this->vx = vx; 
    this->vy = vy; 
    this->s  = s; 
    this->d  = d;  
    this->v  = sqrt(vx*vx + vy*vy); 
    this->a  = a; 
    this->d_dot = d_dot;
    this->d_double_dot = d_double_dot;
    
  };
  
  ~Vehicle() {};
    
    // car's unique ID     
    int id;

    // car's x position in map coordinates 
    double x;
    
    // car's y position in map coordinates,     
    double y;
    
    // car's x velocity in m/s
    double vx;
    
    // car's y velocity in m/s
    double vy;
    
    // car's s position in frenet coordinates
    double s;
    
    // car's d position in frenet coordinates
    double d;
    
    // car's total velocity in m/s
    double v; // s_dot
    
    // car's total acceleration in m/s/s
    double a; // s_double_dot
    
    // car's d velocity in m/s
    double d_dot;

    // car's d acceleration in m/s/s
    double d_double_dot;
    
    void display(Vehicle &car) { 
      cout << "=== car =================" << endl;
      cout << "id:           " << car.id << endl;
      cout << "x:            " << car.x << endl;
      cout << "y:            " << car.y << endl;
      cout << "vx:           " << car.vx << endl;
      cout << "vy:           " << car.vy << endl;
      cout << "=== car state ===========" << endl;     
      cout << "s:            " << car.s << endl;
      cout << "v (s_dot)     " << car.v << endl;
      cout << "a (s_dbl_dot):" << car.a << endl;
      cout << "d:            " << car.d << endl;
      cout << "d_dot:        " << car.d_dot << endl;
      cout << "d_double_dot: " << car.d_double_dot << endl;     
      cout << "=========================" << endl;
      cout << endl;
            
    };
    
    // Predicts state of vehicle in t seconds (assuming constant acceleration)
    vector<double> state_at(double t) {
      double s = this->s + this->v * t + this->a * t * t / 2;
      double v = this->v + this->a * t;
      return {s, v, this->a, this->d, 0, 0};
    } 
    
};


#endif // VEHICLE_H