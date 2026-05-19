#include "ekf.hpp"

EKF::EKF(int state_dim, int meas_dim) {

  x.setZero(state_dim);
  P.setIdentity(state_dim, state_dim);
}

void EKF::predict(double dt) {

  MatrixXd Phi = F(x, dt);
  x = f(x, dt);
  P = Phi * P * Phi.transpose() + Q;
}

void EKF::update(const VectorXd& z, const VectorXd& erg_w) {

  MatrixXd H_j = H(x);
  MatrixXd S = H_j * P * H_j.transpose() + erg_w.asDiagonal() * R; // ergodic weight on measurement noise
  MatrixXd K = P * H_j.transpose() * S.inverse();
  x = x + K * (z - h(x));
  P = (MatrixXd::Identity(x.size(), x.size()) - K * H_j) * P;
}