#include <avr/io.h>
#include <note_define.h>

uint16_t notesArr[] = {
        
//sloka
	(60<<8)+Dn,
	(60<<8)+An,
        (60<<8)+An,
        (60<<8)+Fn,

        (60<<8)+En,
        (60<<8)+En,
	(60<<8)+En,
	(30<<8)+En,
	(30<<8)+Fn,

	(60<<8)+Dn,
        (60<<8)+An,
	(60<<8)+An,
	(60<<8)+Fn,

        (60<<8)+En,
        (60<<8)+En,
	(60<<8)+En,
	(30<<8)+En,
	(30<<8)+Fn,

	(60<<8)+Dn,
	(60<<8)+An,
        (60<<8)+An,
        (60<<8)+Fn,

        (60<<8)+En,
        (60<<8)+En,
	(60<<8)+En,
	(30<<8)+En,
	(30<<8)+Fn,

	(60<<8)+Dn,
	(60<<8)+An,
        (60<<8)+An,
        (60<<8)+Fn,

        (240<<8)+En,

//refren
	(30<<8)+An,
	(60<<8)+Cn,
	(60<<8)+Dn,

	(90<<8)+En,
	(30<<8)+En,
	(45<<8)+En,
	
	(45<<8)+cn,
	(180<<8)+cn,
	
	(30<<8)+Cn,	
	(30<<8)+Dn,
	(120<<8)+En,

	(30<<8)+Dn,
	(15<<8)+En,
	(15<<8)+Dn,
	(30<<8)+En,

	(30<<8)+Fn,
	(60<<8)+En,
	(60<<8)+Dn,


	(30<<8)+An,
	(60<<8)+Cn,
	(60<<8)+Dn,

	(90<<8)+En,
	(30<<8)+En,
	(45<<8)+En,
	
	(45<<8)+cn,
	(180<<8)+cn,
	
	(30<<8)+Cn,	
	(30<<8)+Dn,
	(120<<8)+En,

	(30<<8)+Dn,
	(15<<8)+En,
	(15<<8)+Dn,
	(30<<8)+En,

	(30<<8)+Dn,
	(60<<8)+Fn,

	(30<<8)+En,
	(30<<8)+Dn,
	(120<<8)+cn,
		  
};