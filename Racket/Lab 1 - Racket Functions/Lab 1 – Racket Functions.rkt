;Dylan Lucero, CSC240, 9/5/23

#lang racket

;1. ------------ Celsius to Fahrenheit Function ------------

(define (c->f c)
  (+ 32 (* c (/ 9 5)))      ;equates to (9/5)*C+32
  )

;2. ------------ Quadratic Functions ------------

(define (discrim a b c)
  (- (expt b 2) (* 4 a c)))  ;equates to b^2 - 4ac
  
(define (quad+ a b c)
  (/ (- (sqrt(discrim a b c)) b) (* 2 a)))       ;equivalent to (-b + sqrt(b^2 - 4ac))/2a

(define (quad- a b c)
  (/ (- ( - (sqrt(discrim a b c))) b) (* 2 a)))  ;;equivalent to (-b - sqrt(b^2 - 4ac))/2a

;3. ------------ Quadrant Function------------

(define (quadrant x y)
  (if (and (> x 0) (> y 0)) "Quadrant 1"       ;If elseif chain checking if x or y = 1 || x or y = 0
      (if (and (< x 0) (< y 0)) "Quadrant 3"
          (if (and (> x 0) (< y 0)) "Quadrant 4"
              (if (and (< x 0) (> y 0)) "Quadrant 2"
                  "Origin")))))                      ;Final else returns origin for 0,0

;4a. ------------ Sum of Squares (first nth) -----------------

(define (sum n)
  (if (= n 0)    ;Base Case: if n = 0, return 0
      0
      (+ (* n n) (sum (- n 1))))) ;Recursive Case: iterate till n = 0 calling sum
                                  ;Square n, then add.

;4b. ------------ Square of Sums (first nth) ------------------

(define (square n)
  (sqr (/ (* n (+ n 1)) 2))) ;This function use a basic infinite series
                             ;to add up n numbers. Then square it.

;4c. ------------ Difference (first n) ------------

(define (difference n)
  (- (square n) (sum n)))   ;Subtracts Sum of Squares with Square of Sums