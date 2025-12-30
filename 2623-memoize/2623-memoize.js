/**
 * @param {Function} fn
 * @return {Function}
 */
var memoize = function(fn) {
    const cache = new Map();
    let callCount = 0;

    return function(...args) {
        // yeh getcall and Calls walle comms []=callCounts
        if (args.length === 0) {
            return callCount;
        }

        const key = JSON.stringify(args);

        if (cache.has(key)) {
            return cache.get(key);
        }

        callCount++;
        const result = fn(...args);
        cache.set(key, result);
        return result;
    };
};



/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */