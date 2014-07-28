using System;
using System.Linq;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace snowcrashCLR.tests {
    [TestClass]
    public class snowcrash_action_tests {
        private Blueprint _blueprint;
        private Result _result;
        private Action _action;

        [TestInitialize]
        public void initialize() {
            SnowCrashCLR.parse(source.API.Replace("\r", string.Empty), out _blueprint, out _result);
            var resource = _blueprint.GetResourceGroupsCs().FirstOrDefault().GetResourcesCs().FirstOrDefault();
            _action = resource.GetActionsCs().FirstOrDefault();
        }

        [TestMethod]
        public void returns_valid_action_name() {
            Assert.AreEqual(string.Empty, _action.name);
        }

        [TestMethod]
        public void returns_valid_action_description() {
            Assert.AreEqual(string.Empty, _action.description);
        }

        [TestMethod]
        public void returns_valid_action_method() {
            Assert.AreEqual("GET", _action.method);
        }

        [TestMethod]
        public void returns_empty_action_headers_collection() {
            Assert.IsFalse(_action.GetHeadersCs().Any());
        }

        [TestMethod]
        public void returns_empty_action_parameters_collection() {
            Assert.IsFalse(_action.GetParametersCs().Any());
        }

        [TestMethod]
        public void returns_non_empty_action_examples_collection() {
            Assert.IsTrue(_action.GetTransactionExamplesCs().Any());
        }
    }
}
