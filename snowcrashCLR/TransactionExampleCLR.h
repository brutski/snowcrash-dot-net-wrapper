// TransactionExampleCLR.h

#pragma once
#include <cliext/vector>
#include "Blueprint.h"
#include "HelpersCLR.h"
#include "PayloadCLR.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace cliext;

namespace snowcrashCLR {
     /**
	 *	CLR Wrapper for snowcrash::TransactionExample.
	 */
    public ref class TransactionExample {
    private:
        vector<Request^> ^requests;
        vector<Response^> ^responses;
    public:
        String ^name;
        String ^description;    

        vector<Request^>::generic_container ^GetRequestsCpp() {
            return requests;
        }

        ICollection<Request^> ^GetRequestsCs() {
            return requests;
        }
       
        vector<Response^>::generic_container ^GetResponsesCpp() {
            return responses;
        }

        ICollection<Response^> ^GetResponsesCs() {
            return responses;
        }

        void wrap(const snowcrash::TransactionExample &transactionExample) {
            name = gcnew String(transactionExample.name.c_str());
            description = gcnew String(transactionExample.description.c_str());

            requests = gcnew vector<Request^>();
            for(snowcrash::Collection<snowcrash::Request>::const_iterator requestIterator = transactionExample.requests.begin();
                requestIterator != transactionExample.requests.end(); ++requestIterator) {
                Request ^request = gcnew Request();
                request->wrap(*requestIterator);
                requests->push_back(request);
            }

            responses = gcnew vector<Response^>();
            for(snowcrash::Collection<snowcrash::Response>::const_iterator responseIterator = transactionExample.responses.begin();
                responseIterator != transactionExample.responses.end(); ++responseIterator) {
                Response ^response = gcnew Response();
                response->wrap(*responseIterator);
                responses->push_back(response);
            }
        }
    };
}