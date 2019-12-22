# Bucklescript bindings to date-fns

## New 2.x bindings

You can `npm install bs-date-bns@next` for the new 2.x date-fns bindings which have been switched to t-first convention so you should use `->` instead of `|>` to pipe arguments. It is more in line with the rest of ecosystem and will lead to smaller bundle sizes, because flipping arguments has led to problems with tree-shaking. However that does mean breaking changes. Also it's a major version bump in date-fns itself so that has caused breaking-changes too, refer to date-fns documentation for that.

## 1.x bindings

Current default npm release includes bindings for all date-fns functions using 1.x. It's missing support for locales.

## Getting started

```bash
npm install bs-date-fns --save
```

Add `"bs-date-fns"` to `bs-dependencies` in your project's `bsconfig.json`

## Differences from original date-fns API

In bindings the date parameter is moved to last position in a bunch of functions to work better with currying and make better use of pipe operator. Most of these can be seen from types. The ones that have same types but are different from date-fns:

```rs
laterDate |> DateFns.isAfter(earlierDate) /* true */
DateFns.isAfter(earlierDate, laterDate) /* true */

earlierDate |> DateFns.isBefore(laterDate) /* true */
DateFns.isBefore(laterDate, earlierDate) /* true */

middleDate |> DateFns.isWithinRange(earliestDate, latestDate) /* true */
DateFns.isWithinRange(earliestDate, latestDate, middleDate) /* true */
```
