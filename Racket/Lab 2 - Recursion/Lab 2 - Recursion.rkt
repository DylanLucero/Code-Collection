;Dylan Lucero

#lang racket

(define colors '("red" "white" "and" "blue"))
(define emptyList '())

;basic comparison of 2 strings
(define (longer-string str1 str2)
  (if (> (string-length str1) (string-length str2))
      str1
      str2))

;longest in a list of strings using a helper function to compare
(define (longest-in-list ls)
  (if (null? (cdr ls))
      (car ls)
      (longer-string (car ls)
                     (longest-in-list (cdr ls)))))

;2)
;These functions check the list recursively to find the longest string.
;The first pass checks to see if the list is null. If the list is null, we check
;the first element. If the list is not null, the longer-string function is called
;using the first element as a parameter. The longer-string function checks to see if
;the second string is greater than string 1, then returns the larger value.
;The first pass compares "red" to null, The second pass compares "red" to "white"
;since "white has a longer length than "red", "white" is returned. The third pass
;consists of checking "white" to "and" with "white" still being larger. The final
;pass of the recursive call is checking "white" with "blue". Since "white" is longer,
;the final answer we get is "white"


;3)
;a) When we pass an empty list through the longest-in-list function, we get a contract violation.
;   This error happens when we cdr the empty list since there are no elements in the list.

;b) To solve this, we could add a check early in the function that could return a boolean value
;   if it is null or continue on as normal.
;   e.g. we could use an (if (null? ls)).




;4) mult5 function: return amount of list elements that are multiples of 5
(define (mult5 lst)
  (cond
    ((null? lst) 0)        ; Checks if list is empty
    ((= 0 (modulo (car lst) 5))   ; Checks if the first element is a multiple of 5
     (+ 1 (mult5 (cdr lst))))     ; If yes, add 1 and recurive call
    (else (mult5 (cdr lst))))) 


;5) 5. sumAdj function: Sums adjacent pairs - try another way
(define (sumAdj lst)
  (if (or (null? lst) (null? (cdr lst)))  ; Base case: Checks to see if the list has more than 1 element
      0
      (+ (+ (car lst) (cadr lst))         ; Add the current element and the next element.
         (sumAdj (cdr (cdr lst))))))



;6) getLast function. - try with if else
(define (getlast lst)
  (cond
    ((null? lst) "empty list")    ; Base case: return "empty list" for an empty list
    ((null? (cdr lst)) (car lst)) ; Return the last element when there's only one element left
    (else (getlast (cdr lst)))))



;7) removeLast function:



;8) sumSeries function:
(define (sumSeries inc delta n)
  (if (= n 0)     ; Base case: return an empty list when n is 0
      '()          
      (cons inc
            (sumSeries (+ inc delta) delta (- n 1))))) ; Recursively calls sumSeries with new parameters and cons inc to list



;9) remove-large function: 



;10) sqr-each function:
(define (sqr-each lst)
  (if (null? lst) ; Checks if list is empty
      '()
      (cons (* (car lst) (car lst)) ; Squares current element and cons it to list
            (sqr-each (cdr lst))))) ; Recursive call for next element



;11) repeat function:
(define (repeat size item)
  (if (= size 0) ; Checks if size is 0
      '()
      (cons item
            (repeat (- size 1) item)))) ; Recursively calls repeat with new parameters and cons item to list