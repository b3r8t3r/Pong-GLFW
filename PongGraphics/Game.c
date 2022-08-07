#include "Game.h"

float ratio;

const int final_score = 5;

const float DEG2RAD = 3.14159 / 100;

void Move_Racket(T_Racket* racket, float dy) { racket->y += dy; }



int Left_Racket_Collide(T_Ball* ball, T_Racket* Left_Rack) {
  return (((ball->x + ball->dx) < (Left_Rack->x + Left_Rack->x_size / 2)) &&
          (ball->y < (Left_Rack->y + Left_Rack->y_size / 2) * ratio &&
           ball->y > (Left_Rack->y - Left_Rack->y_size / 2) * ratio));
}

int Right_Racket_Collide(T_Ball* ball, T_Racket* Right_Rack) {
  return (((ball->x + ball->dx) > (Right_Rack->x - Right_Rack->x_size / 2)) &&
          (ball->y < (Right_Rack->y + Right_Rack->y_size / 2) * ratio &&
           ball->y > (Right_Rack->y - Right_Rack->y_size / 2) * ratio));
}

int Racket_Collide(T_Ball* ball, T_Racket* Left_Rack, T_Racket* Right_Rack) {
  return (Left_Racket_Collide(ball, Left_Rack) || Right_Racket_Collide(ball,Right_Rack));
}

int Border_X_Left_Collide(T_Ball* ball) {
  return (ball->x + ball->dx < (- 1 + ball->radius));
}

int Border_X_Right_Collide(T_Ball* ball) {
  return (ball->x + ball->dx > (1 - ball->radius));
}

int Border_Y_Up_Collide(T_Ball* ball) {
  return (ball->y + ball->dy > (1 - ball->radius * ratio));
}

int Border_Y_Down_Collide(T_Ball* ball) {
  return (ball->y + ball->dy < (- 1 + ball->radius * ratio));
}

int Border_X_Collide(T_Ball* ball) {
  return (Border_X_Left_Collide(ball) ||
          Border_X_Right_Collide(ball));
}

int Border_Y_Collide(T_Ball* ball) {
  return (Border_Y_Up_Collide(ball) ||
      Border_Y_Down_Collide(ball));
}

void Ball_Collide(T_Ball* ball, T_Racket* Left_Rack, T_Racket* Right_Rack, T_Score* Score) {
  if (Border_X_Collide(ball)) {
    if (Border_X_Right_Collide(ball)) {
      Increase_Player_1(Score);
      Reset_Round(ball, Left_Rack, Right_Rack);
    } else if (Border_X_Left_Collide(ball)) {
      Increase_Player_2(Score);
      Reset_Round(ball, Left_Rack, Right_Rack);
    } else ball->dx *= -1;
  } else {
    ball->x += ball->dx;
  }

  if (Border_Y_Collide(ball)) {
    ball->dy *= -1;
  } else {
    ball->y += ball->dy;
  }

  if (Racket_Collide (ball,Left_Rack,Right_Rack)) {
    ball->dx *= -1;
  }
}

void Increase_Player_1(T_Score* score) { score->Player_1++; }

void Increase_Player_2(T_Score* score) { score->Player_2++; }

void Reset_Ball(T_Ball* ball) {
  ball->x = 0;
  ball->y = 0;
  ball->dx = 0.01;
  ball->dy = 0.001;
  ball->speedmult = 1;
}

void Reset_racket(T_Racket* racket) { racket->y = 0; }

void Reset_Round(T_Ball* ball, T_Racket* Left_Rack, T_Racket* Right_Rack) {
  Reset_Ball(ball);
  Reset_racket(Left_Rack);
  Reset_racket(Right_Rack);
}

void Keystroke(GLFWwindow* window,T_Ball* ball, T_Racket* Left_Rack, T_Racket* Right_Rack,
               float dy_change) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, 1);
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    if (Left_Rack->y + dy_change < (1 - Left_Rack->y_size * ratio / 2) / ratio)
      Move_Racket(Left_Rack, dy_change);
  if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
    if (Left_Rack->y - dy_change > (-1 + Left_Rack->y_size * ratio / 2) / ratio)
      Move_Racket(Left_Rack, -dy_change);
  if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
    if (Right_Rack->y + dy_change <
        (1 - Right_Rack->y_size * ratio / 2) / ratio)
      Move_Racket(Right_Rack, dy_change);
  if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
    if (Right_Rack->y - dy_change >
        (-1 + Right_Rack->y_size * ratio / 2) / ratio)
      Move_Racket(Right_Rack, -dy_change);
  if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
    Reset_Round(ball, Left_Rack, Right_Rack);
  }
}