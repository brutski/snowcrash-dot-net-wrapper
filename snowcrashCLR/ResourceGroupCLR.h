// ResourceGroupCLR.h

#pragma once
#include <cliext/vector>
#include "Blueprint.h"
#include "ResourceCLR.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace cliext;

namespace snowcrashCLR{
    /**
	 *	CLR Wrapper for snowcrash::ResourceGroup.
	 */
	public ref class ResourceGroup
	{
	private:
		vector<Resource^> ^resources;
	public:
		String ^name;
		String ^description;

        vector<Resource^>::generic_container ^GetResourcesCpp() {
            return resources;
        }

        ICollection<Resource^> ^GetResourcesCs() {
            return resources;
        }

		~ResourceGroup()
		{
			delete resources;
		}

		void wrap(const snowcrash::ResourceGroup &group)
		{
			// Wrap Group Name
			name = gcnew String(group.name.c_str());

			// Wrap Group Description
			description = gcnew String(group.description.c_str());

            // Wrap Resources
            resources = gcnew vector<Resource^>();
			for (snowcrash::Collection<snowcrash::Resource>::const_iterator resourceIterator = group.resources.begin();
				 resourceIterator != group.resources.end();
				 ++resourceIterator) {
				
				Resource ^resource = gcnew Resource();
				resource->wrap(*resourceIterator);
				resources->push_back(resource);
			}
		}
	};
}