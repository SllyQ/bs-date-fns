let flip = (f) => (a, b) => f(b, a);
let handleOptBool = optBool => optBool
  |> Js.Option.map([@bs] bool => bool ? Js.true_ : Js.false_)
  |> Js.Nullable.from_opt;

type timeUnit = | Second | Minute | Hour | Day | Month | Year;
type partialMethod = | Floor | Ceil | Round;

let timeUnitToString = fun
  | Second => "s"
  | Minute => "m"
  | Hour => "h"
  | Day => "d"
  | Month => "M"
  | Year => "Y";
let partialMethodToString = fun
  | Floor => "floor"
  | Ceil => "ceil"
  | Round => "round";

[@bs.val] [@bs.module "date-fns"] external internal_closestIndexTo : (Js.Date.t, array(Js.Date.t)) => int = "closestIndexTo";
let closestIndexTo = flip(internal_closestIndexTo);
[@bs.val] [@bs.module "date-fns"] external internal_closestTo : (Js.Date.t, array(Js.Date.t)) => Js.Date.t = "closestTo";
let closestTo = flip(internal_closestTo);
[@bs.val] [@bs.module "date-fns"] external compareAsc : (Js.Date.t, Js.Date.t) => int = "";
[@bs.val] [@bs.module "date-fns"] external compareDesc : (Js.Date.t, Js.Date.t) => int = "";
type distanceInWordsOptions = {.
  "includeSeconds": Js.Nullable.t(Js.boolean),
  "addSuffix": Js.Nullable.t(Js.boolean),
};
[@bs.val] [@bs.module "date-fns"] external internal_distanceInWords : (Js.Date.t, Js.Date.t, distanceInWordsOptions) => string = "distanceInWords";
let distanceInWords = (~includeSeconds=?, ~addSuffix=?, dateToCompare, date) =>
  internal_distanceInWords(dateToCompare, date, {
    "includeSeconds": includeSeconds |> handleOptBool,
    "addSuffix": addSuffix |> handleOptBool
  });
type distanceInWordsStrictOptions = {.
  "addSuffix": Js.Nullable.t(Js.boolean),
  "unit": Js.Nullable.t(string),
  "partialMethod": Js.Nullable.t(string)
};
[@bs.val] [@bs.module "date-fns"] external internal_distanceInWordsStrict : (Js.Date.t, Js.Date.t, distanceInWordsStrictOptions) => string = "distanceInWordsStrict";
let distanceInWordsStrict = (~addSuffix=?, ~unit=?, ~partialMethod=?, dateToCompare, date) =>
  internal_distanceInWordsStrict(dateToCompare, date, {
    "addSuffix": addSuffix |> handleOptBool,
    "unit": unit
      |> Js.Option.map([@bs] unit => timeUnitToString(unit))
      |> Js.Nullable.from_opt,
    "partialMethod": partialMethod
      |> Js.Option.map([@bs] partialMethod => partialMethodToString(partialMethod))
      |> Js.Nullable.from_opt
  });
type distanceInWordsToNowOptions = {.
  "includeSeconds": Js.Nullable.t(Js.boolean),
  "addSuffix": Js.Nullable.t(Js.boolean)
};
[@bs.val] [@bs.module "date-fns"] external internal_distanceInWordsToNow : (Js.Date.t, distanceInWordsToNowOptions) => string = "distanceInWordsToNow";
let distanceInWordsToNow = (~includeSeconds=?, ~addSuffix=?, date) =>
  internal_distanceInWordsToNow(date, {
    "includeSeconds": includeSeconds |> handleOptBool,
    "addSuffix": addSuffix |> handleOptBool
  });

[@bs.val] [@bs.module "date-fns"] external internal_format : (Js.Date.t, string) => string = "format";
let format = flip(internal_format);
[@bs.val] [@bs.module "date-fns"] external internal_isAfter : (Js.Date.t, Js.Date.t) => bool = "isAfter";
let isAfter = flip(internal_isAfter);
[@bs.val] [@bs.module "date-fns"] external internal_isBefore : (Js.Date.t, Js.Date.t) => bool = "isBefore";
let isBefore = flip(internal_isBefore);
[@bs.val] [@bs.module "date-fns"] external isEqual : (Js.Date.t, Js.Date.t) => bool = "";
[@bs.val] [@bs.module "date-fns"] external isFuture : Js.Date.t => bool = "";
[@bs.val] [@bs.module "date-fns"] external isPart : Js.Date.t => bool = "";
[@bs.val] [@bs.module "date-fns"] external isValid : Js.Date.t => bool = "";
[@bs.val] [@bs.module "date-fns"] external max : array(Js.Date.t) => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external min : array(Js.Date.t) => Js.Date.t = "";
type parseOptions = {.
  "additionalDigits": Js.Nullable.t(int)
};
[@bs.val] [@bs.module "date-fns"] external internal_parseFloat : float => parseOptions => Js.Date.t = "parse";
let parseFloat = (~additionalDigits=?, float) => internal_parseFloat(float, {
  "additionalDigits": additionalDigits |> Js.Nullable.from_opt
});
[@bs.val] [@bs.module "date-fns"] external internal_parseString : string => parseOptions => Js.Date.t = "parse";
let parseString = (~additionalDigits=?, string) => internal_parseString(string, {
  "additionalDigits": additionalDigits |> Js.Nullable.from_opt
});
[@bs.val] [@bs.module "date-fns"] external areRangesOverlapping : (Js.Date.t, Js.Date.t, Js.Date.t, Js.Date.t) => bool = "";
[@bs.val] [@bs.module "date-fns"] external getOverlappingDaysInRanges : (Js.Date.t, Js.Date.t, Js.Date.t, Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external internal_isWithinRange : (Js.Date.t, Js.Date.t, Js.Date.t) => bool = "isWithinRange";
let isWithinRange = (startDate, endDate, date) => internal_isWithinRange(date, startDate, endDate);

[@bs.val] [@bs.module "date-fns"] external getTime : Js.Date.t => float = "";
[@bs.val] [@bs.module "date-fns"] external getMilliseconds : (Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external getSeconds : (Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external getMinutes : (Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external getHours : (Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external getDate : (Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external getDayOfYear : (Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external getDay : (Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external getISODay : (Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external getISOWeek : (Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external getDaysInMonth : (Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external getMonth : (Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external getQuarter : (Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external getDaysInYear : (Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external getYear : (Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external getISOWeeksInYear : (Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external getISOYear : (Js.Date.t) => float = "";

[@bs.val] [@bs.module "date-fns"] external internal_setMilliseconds : (Js.Date.t, float) => Js.Date.t = "setMilliseconds";
[@bs.val] [@bs.module "date-fns"] external internal_setSeconds : (Js.Date.t, float) => Js.Date.t = "setSeconds";
[@bs.val] [@bs.module "date-fns"] external internal_setMinutes : (Js.Date.t, float) => Js.Date.t = "setMinutes";
[@bs.val] [@bs.module "date-fns"] external internal_setHours : (Js.Date.t, float) => Js.Date.t = "setHours";
[@bs.val] [@bs.module "date-fns"] external internal_setDate : (Js.Date.t, float) => Js.Date.t = "setDate";
[@bs.val] [@bs.module "date-fns"] external internal_setDayOfYear : (Js.Date.t, float) => Js.Date.t = "setDayOfYear";
[@bs.val] [@bs.module "date-fns"] external internal_setDay : (Js.Date.t, float) => Js.Date.t = "setDay";
[@bs.val] [@bs.module "date-fns"] external internal_setISODay : (Js.Date.t, float) => Js.Date.t = "setISODay";
[@bs.val] [@bs.module "date-fns"] external internal_setISOWeek : (Js.Date.t, float) => Js.Date.t = "setISOWeek";
[@bs.val] [@bs.module "date-fns"] external internal_setMonth : (Js.Date.t, float) => Js.Date.t = "setMonth";
[@bs.val] [@bs.module "date-fns"] external internal_setQuarter : (Js.Date.t, float) => Js.Date.t = "setQuarter";
[@bs.val] [@bs.module "date-fns"] external internal_setYear : (Js.Date.t, float) => Js.Date.t = "setYear";
[@bs.val] [@bs.module "date-fns"] external internal_setISOYear : (Js.Date.t, float) => Js.Date.t = "setISOYear";

let setMilliseconds = flip(internal_setMilliseconds);
let setSeconds = flip(internal_setSeconds);
let setMinutes = flip(internal_setMinutes);
let setHours = flip(internal_setHours);
let setDay = flip(internal_setDay);
let setISODay = flip(internal_setISODay);
let setDate = flip(internal_setDate);
let setDayOfYear = flip(internal_setDayOfYear);
let setISOWeek = flip(internal_setISOWeek);
let setMonth = flip(internal_setMonth);
let setQuarter = flip(internal_setQuarter);
let setYear = flip(internal_setYear);
let setISOYear = flip(internal_setISOYear);

[@bs.val] [@bs.module "date-fns"] external internal_subMilliseconds : (Js.Date.t, float) => Js.Date.t = "subMilliseconds";
[@bs.val] [@bs.module "date-fns"] external internal_subSeconds : (Js.Date.t, float) => Js.Date.t = "subSeconds";
[@bs.val] [@bs.module "date-fns"] external internal_subMinutes : (Js.Date.t, float) => Js.Date.t = "subMinutes";
[@bs.val] [@bs.module "date-fns"] external internal_subHours : (Js.Date.t, float) => Js.Date.t = "subHours";
[@bs.val] [@bs.module "date-fns"] external internal_subDays : (Js.Date.t, float) => Js.Date.t = "subDays";
[@bs.val] [@bs.module "date-fns"] external internal_subWeeks : (Js.Date.t, float) => Js.Date.t = "subWeeks";
[@bs.val] [@bs.module "date-fns"] external internal_subMonths : (Js.Date.t, float) => Js.Date.t = "subMonths";
[@bs.val] [@bs.module "date-fns"] external internal_subQuarters : (Js.Date.t, float) => Js.Date.t = "subQuarters";
[@bs.val] [@bs.module "date-fns"] external internal_subYears : (Js.Date.t, float) => Js.Date.t = "subYears";
[@bs.val] [@bs.module "date-fns"] external internal_subISOYears : (Js.Date.t, float) => Js.Date.t = "subISOYears";

let subMilliseconds = flip(internal_subMilliseconds);
let subSeconds = flip(internal_subSeconds);
let subMinutes = flip(internal_subMinutes);
let subHours = flip(internal_subHours);
let subDays = flip(internal_subDays);
let subWeeks = flip(internal_subWeeks);
let subMonths = flip(internal_subMonths);
let subQuarters = flip(internal_subQuarters);
let subYears = flip(internal_subYears);
let subISOYears = flip(internal_subISOYears);

[@bs.val] [@bs.module "date-fns"] external internal_addMilliseconds : (Js.Date.t, float) => Js.Date.t = "addMilliseconds";
[@bs.val] [@bs.module "date-fns"] external internal_addSeconds : (Js.Date.t, float) => Js.Date.t = "addSeconds";
[@bs.val] [@bs.module "date-fns"] external internal_addMinutes : (Js.Date.t, float) => Js.Date.t = "addMinutes";
[@bs.val] [@bs.module "date-fns"] external internal_addHours : (Js.Date.t, float) => Js.Date.t = "addHours";
[@bs.val] [@bs.module "date-fns"] external internal_addDays : (Js.Date.t, float) => Js.Date.t = "addDays";
[@bs.val] [@bs.module "date-fns"] external internal_addWeeks : (Js.Date.t, float) => Js.Date.t = "addWeeks";
[@bs.val] [@bs.module "date-fns"] external internal_addMonths : (Js.Date.t, float) => Js.Date.t = "addMonths";
[@bs.val] [@bs.module "date-fns"] external internal_addQuarters : (Js.Date.t, float) => Js.Date.t = "addQuarters";
[@bs.val] [@bs.module "date-fns"] external internal_addYears : (Js.Date.t, float) => Js.Date.t = "addYears";
[@bs.val] [@bs.module "date-fns"] external internal_addISOYears : (Js.Date.t, float) => Js.Date.t = "addISOYears";

let addMilliseconds = flip(internal_addMilliseconds);
let addSeconds = flip(internal_addSeconds);
let addMinutes = flip(internal_addMinutes);
let addHours = flip(internal_addHours);
let addDays = flip(internal_addDays);
let addWeeks = flip(internal_addWeeks);
let addMonths = flip(internal_addMonths);
let addQuarters = flip(internal_addQuarters);
let addYears = flip(internal_addYears);
let addISOYears = flip(internal_addISOYears);

[@bs.val] [@bs.module "date-fns"] external isThisSecond : Js.Date.t => bool = "";
[@bs.val] [@bs.module "date-fns"] external isThisMinute : Js.Date.t => bool = "";
[@bs.val] [@bs.module "date-fns"] external isThisHour : Js.Date.t => bool = "";
[@bs.val] [@bs.module "date-fns"] external isToday : Js.Date.t => bool = "";
[@bs.val] [@bs.module "date-fns"] external isYesterday : Js.Date.t => bool = "";
[@bs.val] [@bs.module "date-fns"] external isThisWeek : Js.Date.t => bool = "";
[@bs.val] [@bs.module "date-fns"] external isThisISOWeek : Js.Date.t => bool = "";
[@bs.val] [@bs.module "date-fns"] external isThisMonth : Js.Date.t => bool = "";
[@bs.val] [@bs.module "date-fns"] external isThisQuarter : Js.Date.t => bool = "";
[@bs.val] [@bs.module "date-fns"] external isThisYear : Js.Date.t => bool = "";
[@bs.val] [@bs.module "date-fns"] external isThisISOYear : Js.Date.t => bool = "";

[@bs.val] [@bs.module "date-fns"] external isSameSecond : (Js.Date.t, Js.Date.t) => bool = "";
[@bs.val] [@bs.module "date-fns"] external isSameMinute : (Js.Date.t, Js.Date.t) => bool = "";
[@bs.val] [@bs.module "date-fns"] external isSameHour : (Js.Date.t, Js.Date.t) => bool = "";
[@bs.val] [@bs.module "date-fns"] external isSameDay : (Js.Date.t, Js.Date.t) => bool = "";
[@bs.val] [@bs.module "date-fns"] external isSameWeek : (Js.Date.t, Js.Date.t) => bool = "";
[@bs.val] [@bs.module "date-fns"] external isSameISOWeek : (Js.Date.t, Js.Date.t) => bool = "";
[@bs.val] [@bs.module "date-fns"] external isSameMonth : (Js.Date.t, Js.Date.t) => bool = "";
[@bs.val] [@bs.module "date-fns"] external isSameQuarter : (Js.Date.t, Js.Date.t) => bool = "";
[@bs.val] [@bs.module "date-fns"] external isSameYear : (Js.Date.t, Js.Date.t) => bool = "";
[@bs.val] [@bs.module "date-fns"] external isSameISOYear : (Js.Date.t, Js.Date.t) => bool = "";

[@bs.val] [@bs.module "date-fns"] external isMonday : Js.Date.t => bool = "";
[@bs.val] [@bs.module "date-fns"] external isTuesday : Js.Date.t => bool = "";
[@bs.val] [@bs.module "date-fns"] external isWednesday : Js.Date.t => bool = "";
[@bs.val] [@bs.module "date-fns"] external isThursday : Js.Date.t => bool = "";
[@bs.val] [@bs.module "date-fns"] external isFriday : Js.Date.t => bool = "";
[@bs.val] [@bs.module "date-fns"] external isSaturday : Js.Date.t => bool = "";
[@bs.val] [@bs.module "date-fns"] external isSunday : Js.Date.t => bool = "";
[@bs.val] [@bs.module "date-fns"] external isWeekend : Js.Date.t => bool = "";

[@bs.val] [@bs.module "date-fns"] external differenceInMilliseconds : (Js.Date.t, Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external differenceInSeconds : (Js.Date.t, Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external differenceInMinutes : (Js.Date.t, Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external differenceInHours : (Js.Date.t, Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external differenceInCalendarDays : (Js.Date.t, Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external differenceInDays : (Js.Date.t, Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external differenceInCalendarWeeks : (Js.Date.t, Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external differenceInWeeks : (Js.Date.t, Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external differenceInCalendarISOWeeks : (Js.Date.t, Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external differenceInCalendarMonths : (Js.Date.t, Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external differenceInMonths : (Js.Date.t, Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external differenceInCalendarQuarters : (Js.Date.t, Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external differenceInQuarters : (Js.Date.t, Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external differenceInYears : (Js.Date.t, Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external differenceInISOYears : (Js.Date.t, Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external differenceInCalendarYears : (Js.Date.t, Js.Date.t) => float = "";
[@bs.val] [@bs.module "date-fns"] external differenceInCalendarISOYears : (Js.Date.t, Js.Date.t) => float = "";

[@bs.val] [@bs.module "date-fns"] external startOfSecond : Js.Date.t => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external endOfSecond : Js.Date.t => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external startOfMinute : Js.Date.t => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external endOfMinute : Js.Date.t => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external startOfHour : Js.Date.t => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external endOfHour : Js.Date.t => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external startOfDay : Js.Date.t => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external endOfDay : Js.Date.t => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external startOfWeek : Js.Date.t => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external endOfWeek : Js.Date.t => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external startOfISOWeek : Js.Date.t => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external endOfISOWeek : Js.Date.t => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external startOfMonth : Js.Date.t => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external endOfMonth : Js.Date.t => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external startOfQuarter : Js.Date.t => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external endOfQuarter : Js.Date.t => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external startOfYear : Js.Date.t => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external endOfYear : Js.Date.t => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external startOfISOYear : Js.Date.t => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external endOfISOYear : Js.Date.t => Js.Date.t = "";

[@bs.val] [@bs.module "date-fns"] external lastDayOfWeek : Js.Date.t => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external lastDayOfISOWeek : Js.Date.t => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external lastDayOfMonth : Js.Date.t => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external lastDayOfQuarter : Js.Date.t => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external lastDayOfYear : Js.Date.t => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external lastDayOfISOYear : Js.Date.t => Js.Date.t = "";

[@bs.val] [@bs.module "date-fns"] external startOfYesterday : unit => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external endOfYesterday : unit => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external startOfToday : unit => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external endOfToday : unit => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external startOfTomorrow : unit => Js.Date.t = "";
[@bs.val] [@bs.module "date-fns"] external endOfTomorrow : unit => Js.Date.t = "";

[@bs.val] [@bs.module "date-fns"] external isFirstDayOfMonth : Js.Date.t => bool = "";
[@bs.val] [@bs.module "date-fns"] external isLastDayOfMonth : Js.Date.t => bool = "";
[@bs.val] [@bs.module "date-fns"] external isLeapYear : Js.Date.t => bool = "";

[@bs.val] [@bs.module "date-fns"] external eachDay : (Js.Date.t, Js.Date.t) => array(Js.Date.t) = "";
