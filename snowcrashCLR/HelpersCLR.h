// HelpersCLR.h

#pragma once
#include <cliext/vector>

using namespace System;
using namespace System::Collections::Generic;
using namespace cliext;

namespace snowcrashCLR {
    /**
	 *	CLR Wrapper for generic key value pair.
	 */ 
	typedef Tuple<String^, String^> KeyValuePair;

	/**
	 *	CLR Wrapper for metadata key value par.
	 */
	typedef KeyValuePair Metadata;

	/**
	 *	CLR Wrapper for Header key value par.
	 */
    typedef KeyValuePair Header;

    /**
	 *	CLR Wrapper for snowcrash::ParameterUse enum.
	 */
    public enum class ParameterUse {
        UndefinedParameterUse, 
        OptionalParameterUser, 
        RequiredParameterUse
    };
}