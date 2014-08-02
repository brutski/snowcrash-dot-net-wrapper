// ResourceCLR.h

#pragma once
#include <cliext/vector>
#include "Blueprint.h"
#include "HelpersCLR.h"
#include "PayloadCLR.h"
#include "ActionCLR.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace cliext;

namespace snowcrashCLR{
    /**
	 *	CLR Wrapper for snowcrash::Resource.
	 */
    public ref class Resource {
    private:
        vector<Parameter^> ^parameters;
        vector<Header^> ^headers;
        vector<Action^> ^actions;
    public:
        String ^name;
        String ^description;
        String ^uriTemplate;
        ResourceModel ^model;

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

        vector<Action^>::generic_container ^GetActionsCpp() {
            return actions;
        }

        ICollection<Action^> ^GetActionsCs() {
            return actions;
        }

		~Resource()
		{
			delete parameters;
			delete headers;
			delete actions;
		}

        void wrap(const snowcrash::Resource &resource) {
            name = gcnew String(resource.name.c_str());
            description = gcnew String(resource.description.c_str());
            uriTemplate = gcnew String(resource.uriTemplate.c_str());

            model = gcnew ResourceModel();
            model->wrap(resource.model);

            parameters = gcnew vector<Parameter^>();
            for(snowcrash::Collection<snowcrash::Parameter>::const_iterator parameterIterator = resource.parameters.begin();
                parameterIterator != resource.parameters.end();
                ++parameterIterator) {

				Parameter ^parameter = gcnew Parameter();
				parameter->wrap(*parameterIterator);
				parameters->push_back(parameter);
            }

            headers = gcnew vector<Header^>();
			for (snowcrash::Collection<snowcrash::Header>::const_iterator headersIterator = resource.headers.begin();
				 headersIterator != resource.headers.end();
				 ++headersIterator) {
				
				// Since this is a simple tuple we will wrap it here...
				String ^key = gcnew String(headersIterator->first.c_str());
				String ^value = gcnew String(headersIterator->second.c_str());
				headers->push_back(gcnew Header(key, value));
			}

            actions = gcnew vector<Action^>();
			for (snowcrash::Collection<snowcrash::Action>::const_iterator actionIterator = resource.actions.begin();
				 actionIterator != resource.actions.end();
				 ++actionIterator) {
				
				Action ^action = gcnew Action();
				action->wrap(*actionIterator);
				actions->push_back(action);
			}
        }  
    };
}