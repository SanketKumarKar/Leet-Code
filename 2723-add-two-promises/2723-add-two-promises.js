/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = function(promise1, promise2) {
    return Promise.all([promise1, promise2])//resolve all promises.
        .then(([a, b]) => a + b);//values given from the promises are added.
};// can be done using async and await tooo.

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */