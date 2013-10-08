// BlueprintCLR.h

#pragma once
#include <cliext/vector>
#include "Blueprint.h"
#include "HelpersCLR.h"
#include "ResourceGroupCLR.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace cliext;

namespace snowcrashCLR {
	/** 
	 *	CLR Wrapper for snowcrash::Blueprint
	 */
	public ref class Blueprint
	{
	private:
		vector<Metadata^> ^metadata;
		vector<ResourceGroup^> ^resourceGroups;
	
	public:
		/** API name */
		String ^name;

		/** API description */
		String ^description;

		/**
		 *	\brief	API metadata.
		 *
         *	This method can be called by a C++ class
         *	in another assembly to get access to the
         *	private STL/CLR type defined above.
		 */
        vector<Metadata ^>::generic_container ^GetMetadataCpp()
		{
			return metadata;
		}

		/**
		 *	\brief	API metadata.
		 *
		 * This method can be called by a non-C++ class
         * in another assembly to get access to the
         * private STL/CLR type defined above.
		 */
		ICollection<Metadata ^> ^GetMetadataCs()
		{
			return metadata;
		}

		/**
		 *	\brief	Resource Groups.
		 */
        vector<ResourceGroup ^>::generic_container ^GetResourceGroupsCpp()
		{
			return resourceGroups;
		}

		ICollection<ResourceGroup ^> ^GetResourceGroupsCs()
		{
			return resourceGroups;
		}

		/**
		 *	\brief	Wrap Snow Crash Blueprint.
		 *	\param	blueprint	A Snow Crash blueprint to wrap.
		 */
		void wrap(const snowcrash::Blueprint& blueprint)
		{
			// Wrap API Name
			name = gcnew String(blueprint.name.c_str());

			// Wrap API Description
			description = gcnew String(blueprint.description.c_str());

			// Wrap Metadata
			metadata = gcnew vector<Metadata^>();
			for (snowcrash::Collection<snowcrash::Metadata>::const_iterator metadataIterator = blueprint.metadata.begin();
				 metadataIterator != blueprint.metadata.end();
				 ++metadataIterator) {
				
				// Since this is a simple tuple we will wrap it here...
				String ^key = gcnew String(metadataIterator->first.c_str());
				String ^value = gcnew String(metadataIterator->second.c_str());
				metadata->push_back(gcnew Metadata(key, value));
			}

			// Wrap Resource Groups
			resourceGroups = gcnew vector<ResourceGroup^>();
			for (snowcrash::Collection<snowcrash::ResourceGroup>::const_iterator groupIterator = blueprint.resourceGroups.begin();
				groupIterator != blueprint.resourceGroups.end();
				++groupIterator) {

				ResourceGroup ^group = gcnew ResourceGroup();
				group->wrap(*groupIterator);  // Let ResourceGroup::wrap() do the work
				resourceGroups->push_back(group);
			}
		}
	};
}
