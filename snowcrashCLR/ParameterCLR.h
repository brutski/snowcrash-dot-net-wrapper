// ParameterCLR.h

#pragma once
#include <cliext/vector>
#include "Blueprint.h"
#include "HelpersCLR.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace cliext;

namespace snowcrashCLR{
    /**
	 *	CLR Wrapper for snowcrash::Parameter.
	 */
    public ref class Parameter{
    private:
        vector<String^> ^values;
    public:
        String ^name;
        String ^description;
        String ^type;
        ParameterUse use;
        String ^defaultValue;
        String ^exampleValue;
          
        vector<String^>::generic_container ^GetValuesCpp() {
            return values;
        }

        ICollection<String^> ^GetValuesCs() {
            return values;
        }

        void wrap(const snowcrash::Parameter &parameter) {
            name = gcnew String(parameter.name.c_str());
            description = gcnew String(parameter.description.c_str());
            type = gcnew String(parameter.type.c_str());
            defaultValue = gcnew String(parameter.defaultValue.c_str());
            exampleValue = gcnew String(parameter.exampleValue.c_str());
            use = static_cast<ParameterUse>(parameter.use);

            values = gcnew vector<String^>();
            for(snowcrash::Collection<snowcrash::Value>::const_iterator valuesIterator = parameter.values.begin();
                valuesIterator != parameter.values.end();
                ++valuesIterator){
				String ^value = gcnew String(valuesIterator->c_str());
				values->push_back(value);
            }
        };
    };
}