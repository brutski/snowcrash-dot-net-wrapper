using System;
using System.Linq;
using snowcrashCLR.tests;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace snowcrashCLR.tests {
    [TestClass]
    public class snowcrash_blueprint_tests {
        private Blueprint _blueprint;
        private Result _result;
         
        [TestInitialize]
        public void initialize(){
            SnowCrashCLR.parse(source.API.Replace("\r", string.Empty), out _blueprint, out _result);                
        } 

        [TestMethod]
        public void returns_valid_api_name() {
            Assert.AreEqual("The Simplest API", _blueprint.name);
        }

        [TestMethod]
        public void returns_valid_api_description() {
            Assert.IsTrue(_blueprint.description.StartsWith("This is one of the simplest APIs written in the **API Blueprint**."));
        }

        [TestMethod]
        public void returns_non_empty_resource_groups_collection() {
            Assert.IsTrue(_blueprint.GetResourceGroupsCs().Any());
        }

        [TestMethod]
        public void returns_non_empty_metadata_collection() {
            Assert.IsTrue(_blueprint.GetMetadataCs().Any());
        }

        [TestMethod]
        public void returns_metadata() {
            var metadata = _blueprint.GetMetadataCs().FirstOrDefault();
            Assert.IsNotNull(metadata);
        }

        [TestMethod]
        public void returns_valid_metadata() {
            var metadata = _blueprint.GetMetadataCs().FirstOrDefault();
            Assert.AreEqual(metadata.Item1, "FORMAT");
            Assert.AreEqual(metadata.Item2, "X-1A");
        }
    }
}
