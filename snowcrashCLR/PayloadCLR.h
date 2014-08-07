// PayloadCLR.h

#pragma once
#include <cliext/vector>
#include "Blueprint.h"
#include "HelpersCLR.h"
#include "ParameterCLR.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace cliext;

namespace snowcrashCLR{
    /**
	 *	CLR Wrapper for snowcrash::Payload.
	 */
    public ref class Payload {
    private:
        vector<Parameter^> ^parameters;
        vector<Header^> ^headers;
    public:
        String ^name;
        String ^description;
        String ^schema;
        String ^body;

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

		~Payload()
		{
			delete headers;
			delete parameters;
		}
        
        void wrap(const snowcrash::Payload &payload) {
            name = gcnew String(payload.name.c_str());
            description = gcnew String(payload.description.c_str());
            schema = gcnew String(payload.schema.c_str());
            body = gcnew String(payload.body.c_str());

            parameters = gcnew vector<Parameter^>();
            for(snowcrash::Collection<snowcrash::Parameter>::const_iterator parameterIterator = payload.parameters.begin();
                parameterIterator != payload.parameters.end();
                ++parameterIterator) {

				Parameter ^parameter = gcnew Parameter();
				parameter->wrap(*parameterIterator);
				parameters->push_back(parameter);
            }

			headers = gcnew vector<Header^>();
			for (snowcrash::Collection<snowcrash::Header>::const_iterator headersIterator = payload.headers.begin();
				 headersIterator != payload.headers.end();
				 ++headersIterator) {
				
				// Since this is a simple tuple we will wrap it here...
				String ^key = gcnew String(headersIterator->first.c_str());
				String ^value = gcnew String(headersIterator->second.c_str());
				headers->push_back(gcnew Header(key, value));
			}
        } 
    };

    typedef Payload ResourceModel;
    typedef Payload Request;
    typedef Payload Response;
}