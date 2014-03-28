// ActionCLR.h

#pragma once
#include <cliext/vector>
#include "Blueprint.h"
#include "HelpersCLR.h"
#include "TransactionExampleCLR.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace cliext;

namespace snowcrashCLR{
    /**
	 *	CLR Wrapper for snowcrash::Action.
	 */
    public ref class Action {
    private:
        vector<Parameter^> ^parameters;
        vector<Header^> ^headers;
        vector<TransactionExample^> ^examples;  
    public:
        String ^name;
        String ^description;
        String ^method;

        vector<Parameter^>::generic_container ^GetParametersCpp() {
            return parameters;
        }

        ICollection<Parameter^> ^GetParametersCs() {
            return parameters;
        }

        vector<Header^>::generic_container ^GetHeadersCpp() {
            return headers;
        }

        ICollection<Header^> ^GetHeadersCs() {
            return headers;
        }

        vector<TransactionExample^>::generic_container ^GetTransactionExamplesCpp() {
            return examples;
        }

        ICollection<TransactionExample^> ^GetTransactionExamplesCs() {
            return examples;
        }

        void wrap(const snowcrash::Action &action) {
            name = gcnew String(action.name.c_str());
            description = gcnew String(action.description.c_str());
            method = gcnew String(action.method.c_str());

            parameters = gcnew vector<Parameter^>();
            for(snowcrash::Collection<snowcrash::Parameter>::const_iterator parameterIterator = action.parameters.begin();
                parameterIterator != action.parameters.end();
                ++parameterIterator) {

				Parameter ^parameter = gcnew Parameter();
				parameter->wrap(*parameterIterator);
				parameters->push_back(parameter);
            }

            headers = gcnew vector<Header^>();
			for (snowcrash::Collection<snowcrash::Header>::const_iterator headersIterator = action.headers.begin();
				 headersIterator != action.headers.end();
				 ++headersIterator) {
				
				// Since this is a simple tuple we will wrap it here...
				String ^key = gcnew String(headersIterator->first.c_str());
				String ^value = gcnew String(headersIterator->second.c_str());
				headers->push_back(gcnew Header(key, value));
			}

            examples = gcnew vector<TransactionExample^>();
			for (snowcrash::Collection<snowcrash::TransactionExample>::const_iterator examplesIterator = action.examples.begin();
				 examplesIterator != action.examples.end();
				 ++examplesIterator) {
				
                TransactionExample ^example = gcnew TransactionExample();
				example->wrap(*examplesIterator);
                examples->push_back(example);
			}
        }
    };
}
