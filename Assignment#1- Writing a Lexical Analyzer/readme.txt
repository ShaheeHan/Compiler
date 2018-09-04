1.Please run the "script" file and it will generate the output file(output.out) by taking input from (input.in).

2.
	i)The first two inputs are divisible by 4 and are not more than 4 characters so the output is in the format:token('Div_4*') and then the lexeme.
	ii)The third input is 'AssignOp' and fourth and fifth inputs are signed number and so is my output.
	iii)The sixth input is relational operator and so is the output.
	iv)The 7th and 8th input is decimal number and the output is also produces the same.
	v)The 9th input is "33333" which is a overflow by our defination  and my output  also produces "Overflow 33333".
	vi)The 10th&11th input is hex number but 11th input  overflows ,so my lexer outputs "Oveflow 0xBBBFF".
	vii)12th and 13th input is scientific number  and so is the output.
	viii)14th and 15th both inputs are signed number and my lexer detects them as signed number.
	ix)16th input is ID since it is alphaneumaric character.
	x)Last two inputs are relational oprator.  

3.I haven't encountered any error. 
