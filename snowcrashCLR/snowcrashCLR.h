// snowcrashCLR.h

#pragma once
#include <msclr\marshal_cppstd.h>

#include "snowcrash.h"
#include "BlueprintCLR.h"
#include "SourceAnnotationCLR.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace snowcrashCLR {

	// TODO: Rename
	public ref class SnowCrashCLR
	{
	public:
		/**
		 *	\brief	Parse API Blueprint into AST
		 *	\param	sourceData	An API Blueprint source data.
		 *
		 *	NOTE: Refer to http://stackoverflow.com/questions/3514237/ref-and-out-in-c-cli
		 *	for explanation on the "out" keyword.
		 */
		static int parse(System::String ^source, [Out] Blueprint^% blueprint, [Out] Result^% result)
		{
			// Convert System::string to std::string.
			// Refer to http://stackoverflow.com/questions/1300718/c-net-convert-systemstring-to-stdstring 
			// for explanation on how to convert an unmanaged C++ string (std::string) to CLI.
			msclr::interop::marshal_context context;
			std::string sourceData = context.marshal_as<std::string>(source);

			// Parse source data.
			snowcrash::Result parserResult;
			snowcrash::Blueprint blueprintAST;
			int returnCode = snowcrash::parse(sourceData, 0, parserResult, blueprintAST);

			// Wrap snowcrash::Blueprint.
			blueprint = gcnew Blueprint(); // FIXME: is this needed?
			blueprint->wrap(blueprintAST);

            result = gcnew Result();
            result->wrap(parserResult);
			// TODO: Wrap snowcrash::Result.
			// Something along these lines:
			// result->wrap(parserResult);
			// where result is defined in ResultCLR.h and passed as  [Out] Result^% result
			// e.g. static int parse(System::String ^source, [Out] Result^% result, [Out] Blueprint^% blueprint)

			return returnCode;
		}
	};
}
