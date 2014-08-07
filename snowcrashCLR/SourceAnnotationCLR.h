// SourceAnnotationCLR.h

#pragma once
#include <cliext/vector>
#include "SourceAnnotation.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace cliext;

namespace snowcrashCLR {
    public ref class SourceCharacterRange {
    public:
        size_t location;
        size_t length;
    };

    public ref class SourceAnnotation {
    private:
        vector<SourceCharacterRange^> ^location;
    public:
        String ^message;
        int code;
        
        vector<SourceCharacterRange^>::generic_container ^GetLocationCpp() {
            return location;
        }

        ICollection<SourceCharacterRange^> ^GetLocationCs() {
            return location;
        }

		~SourceAnnotation()
		{
			delete location;
		}

        void wrap(const snowcrash::SourceAnnotation &source) {
            message = gcnew String(source.message.c_str());
            code = source.code;

            location = gcnew vector<SourceCharacterRange^>();
            for(snowcrash::SourceCharactersBlock::const_iterator locationsIterator = source.location.begin();
                locationsIterator != source.location.end();
                ++locationsIterator) {
                SourceCharacterRange ^range = gcnew SourceCharacterRange();
                range->length = locationsIterator->length;
                range->location = locationsIterator->location;
                location->push_back(range);
            } 
        }
    };

    typedef SourceAnnotation Error;

    public enum class ErrorCode {
        NoError = 0,
        ApplicationError = 1,
        BusinessError = 2,
        SymbolError = 3
    };

    typedef SourceAnnotation Warning;

    public enum class WarningCode {
        NoWarning = 0,
        APINameWarning = 1,
        DuplicateWarning = 2,
        FormattingWarning = 3,
        RedefinitionWarning = 4,
        IgnoringWarning = 5,
        EmptyDefinitionWarning = 6,
        NotEmptyDefinitionWarning = 7,
        LogicalErrorWarning = 8,
        DeprecatedWarning = 9
    };

    public ref class Result {
    private:
        Error ^error;
        vector<Warning^> ^warnings;

    public:
        vector<Warning^>::generic_container ^GetWarningsCpp() {
            return warnings;
        }

        ICollection<Warning^> ^GetWarningsCs() {
            return warnings;
        }

		~Result()
		{
			delete warnings;
		}

        void wrap(const snowcrash::Result &result){
            error = gcnew Error();
            error->wrap(result.error);
            
            warnings = gcnew vector<Warning^>();
            for(snowcrash::Warnings::const_iterator warningsIterator = result.warnings.begin();
                warningsIterator != result.warnings.end();
                ++warningsIterator){

                Warning ^warning = gcnew Warning();
                warning->wrap(*warningsIterator);
				warnings->push_back(warning);
            }
        }
    };
}