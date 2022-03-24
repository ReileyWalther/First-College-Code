; ----------------------------------------------------
; Search for the number of lower case vowels in a string
; ----------------------------------------------------
;
; Written by:	Reiley Walther
;
; ----------------------------------------------------

include Irvine32.inc

.data
	prompt BYTE "Enter a string to search: ",0		; initializing a string to prompt the user for input
	userString BYTE 101 DUP(?)						; variable to store user input
	found BYTE "Characters found:",0				; initializing string for before output
	charArray BYTE 26 DUP(?)						; array to store count for characters repeated

.code
main PROC											; Main procedure
	mov edx, OFFSET prompt							; move offset of prompt into EDX register
	call WriteString								; output the prompt variable

	mov edx, OFFSET userString						; move offset of userString into EDX register
	mov ecx, SIZEOF userString-1					; mov the SIZEOF userString-1 (for null terminator) into ECX register

	call ReadString									; reads string from user

	mov ebx,'a'										; sets ebx to first letter of alphabet
	mov esi, 0										; sets esi as index for array to 0

Let:												; loop for each letter (use ascii)
	call CountChar									; call CountChar function
	mov charArray[esi],al							; sets lower eax value into array
	inc ebx											; go to next letter in the alphabet
    add esi, TYPE BYTE								; increments the counter of the index
	cmp bx, '{'										; compare current letter to the character after 'z'
    jae Carryon										; jump to carryon if above or equal
	loop Let											; loop Let
Carryon:

	mov ecx, 26										; sets counter register to 26
	mov ebx, 'a'									; sets ebx to first letter of alphabet
	mov esi,0										; resets index to 0

	mov edx, OFFSET found ;"Characters found:"		; sets edx register to output message before main output
	call WriteString								; writes string
	call Crlf										; new line feed

Output:
	cmp charArray[esi],0							; compares current char to 0
	je exclude										; if current char is 0, jump to exclude

	mov eax, ebx									; move ebx to eax for output
	call WriteChar									; outputs eax char value
	mov eax, ' '
	call WriteChar									; outputs a space

	mov al, charArray[esi]							; moves number in array to lower part of eax
	call WriteDec									; outputs decimal value
	call Crlf										; new line feed

exclude:
	inc ebx											; increments letter in alphabet
	add esi, TYPE BYTE								; increases the index of the array
	loop Output										; loops output

	call WaitMsg									; wait for user to hit enter
	invoke ExitProcess,0							; bye
main ENDP


;-------------------------------------------------------------------------------------
; Procedure   : CountChar
; Description : Search a supplied string for a specific character, counts the number
;               of times it repeats and returns that value
; Receives    : EDX  - string
;               EBX - character to search for
;               ECX - loop counter
; Returns     : EAX - number of times character appears
;-------------------------------------------------------------------------------------
CountChar PROC
	push edx										; pushes registers onto the stack
	push ecx
	push esi


	mov eax, 0										; sets count to 0
	mov esi, edx									; sets esi to edx
	mov dl, 0Ah										; moves 0 into edx

L1:													; loop through the string
	cmp BYTE PTR [esi], bl							; compares value dereferenced to bl
	je next											; jumps to next if equal
	cmp BYTE PTR [esi], dl							; compares value dereferenced to zero
	je done											; jumps to done if equal
	add esi, TYPE BYTE								; increments esi by byte size
	jmp L1
next:
	inc eax											; adds to count to show a letter was found
	add esi, TYPE BYTE								; increments the array index
	jmp L1

done:

	pop esi
	pop ecx											; pops ecx off the stack
	pop edx											; pops edx off the stack
	ret
CountChar ENDP

END main