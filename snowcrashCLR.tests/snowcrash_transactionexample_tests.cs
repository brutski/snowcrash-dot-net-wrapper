using System;
using System.Linq;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace snowcrashCLR.tests {
    [TestClass]
    public class snowcrash_transactionexample_tests {
        private Blueprint _blueprint;
        private Result _result;
        private TransactionExample _example;

        [TestInitialize]
        public void initialize() {
            SnowCrashCLR.parse(source.API.Replace("\r", string.Empty), out _blueprint, out _result);
            var resource = _blueprint.GetResourceGroupsCs().FirstOrDefault().GetResourcesCs().FirstOrDefault();
            _example = resource.GetActionsCs().FirstOrDefault().GetTransactionExamplesCs().FirstOrDefault();
        }

        [TestMethod]
        public void returns_valid_example_name() {
            Assert.AreEqual(string.Empty, _example.name);
        }

        [TestMethod]
        public void returns_valid_example_description() {
            Assert.AreEqual(string.Empty, _example.description);
        }

        [TestMethod]
        public void returns_empty_example_requests_collection() {
            Assert.IsFalse(_example.GetRequestsCs().Any());
        }

        [TestMethod]
        public void returns_non_empty_example_responses_collection() {
            Assert.IsTrue(_example.GetResponsesCs().Any());
        }

        [TestMethod]
        public void returns_valid_example_payload() {
            var response = _example.GetResponsesCs().FirstOrDefault();
            Assert.AreEqual("    Hello World!\n", response.body);
            Assert.AreEqual("200", response.name);
            Assert.AreEqual(string.Empty, response.description);
            Assert.AreEqual(string.Empty, response.schema);
            Assert.IsTrue(response.GetHeadersCs().Any());
            Assert.IsFalse(response.GetParametersCs().Any());
        }

        [TestMethod]
        public void returns_valid_example_headers() {
            var response = _example.GetResponsesCs().FirstOrDefault();
            var header = response.GetHeadersCs().FirstOrDefault();

            Assert.AreEqual("Content-Type", header.Item1);
            Assert.AreEqual("text/plain", header.Item2);
        }
    }
}
