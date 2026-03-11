#ifndef __EKF_H__
#define __EKF_H__

#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

class EKF{

  public:

    EKF(int state_dim, int meas_dim);

    virtual VectorXd f(const VectorXd& x, double dt) = 0; // system dynamics
    virtual MatrixXd F(const VectorXd& x, double dt) = 0; // dynamics jabian
    virtual VectorXd h(const VectorXd& x) = 0; // measurement model
    virtual MatrixXd H(const VectorXd& x) = 0; // Jh jacobian

    void predict(double dt);

    void update(const VectorXd& z);

    VectorXd get_state() const { return x; }
    MatrixXd get_covariance() const { return P; }

  protected:

    VectorXd x; // state
    MatrixXd P; // state covariance
    MatrixXd Q; // process noise
    MatrixXd R; // measurement noise

};

#endif