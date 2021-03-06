/* Automatically generated by
	VMPluginCodeGenerator VMMaker.oscog-eem.2347 uuid: 062614a7-e3da-4b30-997a-9568911b9ff5
   from
	BMPReadWriterPlugin VMMaker.oscog-eem.2347 uuid: 062614a7-e3da-4b30-997a-9568911b9ff5
 */
static char __buildInfo[] = "BMPReadWriterPlugin VMMaker.oscog-eem.2347 uuid: 062614a7-e3da-4b30-997a-9568911b9ff5 " __DATE__ ;



#include "config.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
#include "sqConfig.h"			/* Configuration options */
#include "sqVirtualMachine.h"	/*  The virtual machine proxy definition */
#include "sqPlatformSpecific.h"	/* Platform specific definitions */

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
# undef EXPORT
# define EXPORT(returnType) static returnType
#endif

#include "sqMemoryAccess.h"


/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) primitiveRead24BmpLine(void);
EXPORT(sqInt) primitiveWrite24BmpLine(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*failed)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*isBytes)(sqInt oop);
static sqInt (*isWords)(sqInt oop);
static sqInt (*methodArgumentCount)(void);
static sqInt (*pop)(sqInt nItems);
static sqInt (*primitiveFail)(void);
static sqInt (*slotSizeOf)(sqInt oop);
static sqInt (*stackIntegerValue)(sqInt offset);
static sqInt (*stackObjectValue)(sqInt offset);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt failed(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt isBytes(sqInt oop);
extern sqInt isWords(sqInt oop);
extern sqInt methodArgumentCount(void);
extern sqInt pop(sqInt nItems);
extern sqInt primitiveFail(void);
extern sqInt slotSizeOf(sqInt oop);
extern sqInt stackIntegerValue(sqInt offset);
extern sqInt stackObjectValue(sqInt offset);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"BMPReadWriterPlugin VMMaker.oscog-eem.2347 (i)"
#else
	"BMPReadWriterPlugin VMMaker.oscog-eem.2347 (e)"
#endif
;



/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

	/* InterpreterPlugin>>#getModuleName */
EXPORT(const char*)
getModuleName(void)
{
	return moduleName;
}

	/* BMPReadWriterPlugin>>#primitiveRead24BmpLine */
EXPORT(sqInt)
primitiveRead24BmpLine(void)
{
    unsigned int *formBits;
    sqInt formBitsIndex;
    sqInt formBitsOop;
    sqInt formBitsSize;
    unsigned char *pixelLine;
    sqInt pixelLineOop;
    sqInt pixelLineSize;
    sqInt width;

	if (!((methodArgumentCount()) == 4)) {
		return primitiveFail();
	}
	width = stackIntegerValue(0);
	if (width <= 0) {
		return primitiveFail();
	}
	formBitsIndex = stackIntegerValue(1);
	formBitsOop = stackObjectValue(2);
	pixelLineOop = stackObjectValue(3);
	if (failed()) {
		return null;
	}
	if (!(isWords(formBitsOop))) {
		return primitiveFail();
	}
	if (!(isBytes(pixelLineOop))) {
		return primitiveFail();
	}
	formBitsSize = slotSizeOf(formBitsOop);
	formBits = firstIndexableField(formBitsOop);
	pixelLineSize = slotSizeOf(pixelLineOop);
	pixelLine = firstIndexableField(pixelLineOop);
	if (!(((formBitsIndex + width) <= formBitsSize)
		 && ((width * 3) <= pixelLineSize))) {
		return primitiveFail();
	}
	
	formBits += formBitsIndex-1;
	while(width--) {
		unsigned int rgb;
		rgb = (*pixelLine++);
		rgb += (*pixelLine++) << 8;
		rgb += (*pixelLine++) << 16;
		if(rgb) rgb |= 0xFF000000; else rgb |= 0xFF000001;
		*formBits++ = rgb;
	}
	
	pop(4);
	return 0;
}

	/* BMPReadWriterPlugin>>#primitiveWrite24BmpLine */
EXPORT(sqInt)
primitiveWrite24BmpLine(void)
{
    unsigned int *formBits;
    sqInt formBitsIndex;
    sqInt formBitsOop;
    sqInt formBitsSize;
    unsigned char *pixelLine;
    sqInt pixelLineOop;
    sqInt pixelLineSize;
    sqInt width;

	if (!((methodArgumentCount()) == 4)) {
		return primitiveFail();
	}
	width = stackIntegerValue(0);
	if (width <= 0) {
		return primitiveFail();
	}
	formBitsIndex = stackIntegerValue(1);
	formBitsOop = stackObjectValue(2);
	pixelLineOop = stackObjectValue(3);
	if (failed()) {
		return null;
	}
	if (!(isWords(formBitsOop))) {
		return primitiveFail();
	}
	if (!(isBytes(pixelLineOop))) {
		return primitiveFail();
	}
	formBitsSize = slotSizeOf(formBitsOop);
	formBits = firstIndexableField(formBitsOop);
	pixelLineSize = slotSizeOf(pixelLineOop);
	pixelLine = firstIndexableField(pixelLineOop);
	if (!(((formBitsIndex + width) <= formBitsSize)
		 && ((width * 3) <= pixelLineSize))) {
		return primitiveFail();
	}
	
	formBits += formBitsIndex-1;

	while(width--) {
		unsigned int rgb;
		rgb = *formBits++;
		(*pixelLine++) = (rgb      ) & 0xFF;
		(*pixelLine++) = (rgb >> 8 ) & 0xFF;
		(*pixelLine++) = (rgb >> 16) & 0xFF;
	}

	
	pop(4);
	return 0;
}


/*	Note: This is coded so that it can be run in Squeak. */

	/* InterpreterPlugin>>#setInterpreter: */
EXPORT(sqInt)
setInterpreter(struct VirtualMachine*anInterpreter)
{
    sqInt ok;

	interpreterProxy = anInterpreter;
	ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
	 && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
	if (ok) {
		
#if !defined(SQUEAK_BUILTIN_PLUGIN)
		failed = interpreterProxy->failed;
		firstIndexableField = interpreterProxy->firstIndexableField;
		isBytes = interpreterProxy->isBytes;
		isWords = interpreterProxy->isWords;
		methodArgumentCount = interpreterProxy->methodArgumentCount;
		pop = interpreterProxy->pop;
		primitiveFail = interpreterProxy->primitiveFail;
		slotSizeOf = interpreterProxy->slotSizeOf;
		stackIntegerValue = interpreterProxy->stackIntegerValue;
		stackObjectValue = interpreterProxy->stackObjectValue;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "BMPReadWriterPlugin";
void* BMPReadWriterPlugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "primitiveRead24BmpLine\000\001", (void*)primitiveRead24BmpLine},
	{(void*)_m, "primitiveWrite24BmpLine\000\001", (void*)primitiveWrite24BmpLine},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveRead24BmpLineAccessorDepth = 1;
signed char primitiveWrite24BmpLineAccessorDepth = 1;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
