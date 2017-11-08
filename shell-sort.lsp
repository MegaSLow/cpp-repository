;Shell Sort
;The idea of algorithms is very similar to insertion sort, but in that one you take
; only one element while in this you make sort of sublists by their first elements


;Two case to check 
(shellsort '(1 6 2 4 3 9 10 15 24 67 23 63 24 12 35 85 185) (increment '() (-(ceiling(log 17 3))1) 1 )  17 )
	
(shellsort '(1 6 2 4 85 185) (increment '(1) (-(ceiling(log 3 6))1) 3 ) 6)
	
;Function to calculate increments
(defun increment(lst step val)
 (cond((not(eq step 0)) (increment (cons val lst) (- step 1) (+(* val 3) 1)))
 ((eq step 0) lst) )) 

 ; Main shellsort function
(defun shellsort(lst incs size)
(cond((null incs) lst)
	 (t (shellsort (incsort lst (car incs) size) (cdr incs) size )))
)
;Function for sorting by certain increment
(defun incsort(lst inc size)
(cond((null lst) '())
	 (t (ins (slice lst 1 inc) (incsort (slice lst (+ inc 1) (- size inc)) inc (- size inc)) inc (- size inc)))
))
;Insertion function
(defun ins(e lst inc size)()
(cond((null lst) (append e '()))
	 ((<= (car e) (car lst)) (append e lst))
	 (t  (append (slice lst 1 inc) (ins e (slice lst (+ inc 1) (- size inc) ) inc (- size inc))))))

;Two functions that give you an opportunity to take certain amount of elements counting from start position
(defun getnitems(lst num)
 (cond((> num 0) (cons (car lst) (getnitems (cdr lst) (- num 1))) )
 (t '() )))
 

(defun slice(lst start count)
(cond((> start 1) (slice (cdr lst) (- start 1) count))
(t (getnitems lst count))))


