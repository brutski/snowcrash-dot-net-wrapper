using System;
using System.Linq;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace snowcrashCLR.tests {
    [TestClass]
    public class snowcrash_resource_tests {
        private Blueprint _blueprint;
        private Result _result;
        private Resource _resource;

        [TestInitialize]
        public void initialize() {
            SnowCrashCLR.parse(source.API.Replace("\r", string.Empty), out _blueprint, out _result);
            _resource = _blueprint.GetResourceGroupsCs().FirstOrDefault().GetResourcesCs().FirstOrDefault();
        }

        [TestMethod]
        public void returns_valid_resource_name() {
            Assert.AreEqual(string.Empty, _resource.name);
        }

        [TestMethod]
        public void returns_valid_resource_description() {
            Assert.AreEqual(string.Empty, _resource.description);
        }

        [TestMethod]
        public void returns_valid_resource_uri_template() {
            Assert.AreEqual("/message", _resource.uriTemplate);
        }

        [TestMethod]
        public void returns_valid_resource_model() {
            Assert.IsNotNull(_resource.model);
        }

        [TestMethod]
        public void returns_empty_resource_parameters_collection() {
            Assert.IsFalse(_resource.GetParametersCs().Any());
        }

        [TestMethod]
        public void returns_empty_resource_headers_collection() {
            Assert.IsFalse(_resource.GetHeadersCs().Any());
        }

        [TestMethod]
        public void returns_non_empty_resource_actions_collection() {
            Assert.IsTrue(_resource.GetActionsCs().Any());
        }

        [TestMethod]
        public void returns_valid_resource_payload() {
            var payload = _resource.model;
            Assert.AreEqual(string.Empty, payload.body);
            Assert.AreEqual(string.Empty, payload.description);
            Assert.AreEqual(string.Empty, payload.name);
            Assert.AreEqual(string.Empty, payload.schema);
            Assert.IsFalse(payload.GetHeadersCs().Any());
            Assert.IsFalse(payload.GetParametersCs().Any());
        }
    }
}
