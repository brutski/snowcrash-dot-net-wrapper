using System;
using System.Linq;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace snowcrashCLR.tests {
    [TestClass]
    public class snowcrash_resourcegroup_tests {
        private Blueprint _blueprint;
        private Result _result;
        private ResourceGroup _resourceGroup;

        [TestInitialize]
        public void initialize() {
            SnowCrashCLR.parse(source.API.Replace("\r", string.Empty), out _blueprint, out _result);
            _resourceGroup = _blueprint.GetResourceGroupsCs().FirstOrDefault();
        }

        [TestMethod]
        public void returns_resource_group_with_valid_name() {
            Assert.AreEqual(string.Empty, _resourceGroup.name);
        }

        [TestMethod]
        public void returns_resource_group_with_valid_description() {
            Assert.AreEqual(string.Empty, _resourceGroup.description);
        }

        [TestMethod]
        public void returns_non_empty_resources_collection() {
            Assert.IsTrue(_resourceGroup.GetResourcesCs().Any());
        }
    }
}
