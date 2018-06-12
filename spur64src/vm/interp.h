/* Automatically generated by
	CCodeGeneratorGlobalStructure VMMaker.oscog-eem.2361 uuid: 7ca2f89a-de70-422f-b92b-54f91ac4e47b
 */

#define VM_PROXY_MAJOR 1
#define VM_PROXY_MINOR 14

#define SQ_VI_BYTES_PER_WORD 8

#define BaseHeaderSize 8
#define BytesPerOop 8
#define BytesPerWord 8

#define PrimErrGenericFailure 1
#define PrimErrBadReceiver 2
#define PrimErrBadArgument 3
#define PrimErrBadIndex 4
#define PrimErrBadNumArgs 5
#define PrimErrInappropriate 6
#define PrimErrUnsupported 7
#define PrimErrNoModification 8
#define PrimErrNoMemory 9
#define PrimErrNoCMemory 10
#define PrimErrNotFound 11
#define PrimErrBadMethod 12
#define PrimErrNamedInternal 13
#define PrimErrObjectMayMove 14
#define PrimErrLimitExceeded 15
#define PrimErrObjectIsPinned 16
#define PrimErrWritePastObject 17
#define PrimErrObjectMoved 18
#define PrimErrObjectNotPinned 19
#define PrimErrCallbackError 20
#define PrimErrOSError 21

#define MinSmallInteger -1152921504606846976
#define MaxSmallInteger 1152921504606846975
#define NumSmallIntegerTagBits 3

#define MULTIPLEBYTECODESETS 1
#if !defined(IMMUTABILITY) /* Allow this to be overridden on the compiler command line */
# define IMMUTABILITY 1
#endif

#define STACKVM 1
#define SPURVM 1
#define COGVM 1
#if !defined(COGMTVM)
# define COGMTVM 0
#endif

#define DisownVMLockOutFullGC 1
