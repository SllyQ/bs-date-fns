let flip = (f) => (a, b) => f(b, a);
let handleOptBool = optBool => optBool
  |> Js.Nullable.fromOption;

type timeUnit = | Second | Minute | Hour | Day | Month | Year;
type partialMethod = | Floor | Ceil | Round;

let timeUnitToString = fun
  | Second => "second"
  | Minute => "minute"
  | Hour => "hour"
  | Day => "day"
  | Month => "month"
  | Year => "year";
let partialMethodToString = fun
  | Floor => "floor"
  | Ceil => "ceil"
  | Round => "round";

[@bs.module] external internal_closestIndexTo : (Js.Date.t, array(Js.Date.t)) => int = "date-fns/closestIndexTo";
let closestIndexTo = flip(internal_closestIndexTo);
[@bs.module] external internal_closestTo : (Js.Date.t, array(Js.Date.t)) => Js.Date.t = "date-fns/closestTo";
let closestTo = flip(internal_closestTo);
[@bs.module] external compareAsc : (Js.Date.t, Js.Date.t) => int = "date-fns/compareAsc";
[@bs.module] external compareDesc : (Js.Date.t, Js.Date.t) => int = "date-fns/compareDesc";
type formatDistanceOptions = {.
  "includeSeconds": Js.Nullable.t(bool),
  "addSuffix": Js.Nullable.t(bool),
};
[@bs.module] external internal_formatDistance : (Js.Date.t, Js.Date.t, formatDistanceOptions) => string = "date-fns/formatDistance";
let formatDistance = (~includeSeconds=?, ~addSuffix=?, dateToCompare, date) =>
  internal_formatDistance(dateToCompare, date, {
    "includeSeconds": includeSeconds |> handleOptBool,
    "addSuffix": addSuffix |> handleOptBool
  });
type formatDistanceStrictOptions = {.
  "addSuffix": Js.Nullable.t(bool),
  "unit": Js.Nullable.t(string),
  "roundingMethod": Js.Nullable.t(string)
};
[@bs.module] external internal_formatDistanceStrict : (Js.Date.t, Js.Date.t, formatDistanceStrictOptions) => string = "date-fns/formatDistanceStrict";
let formatDistanceStrict = (~addSuffix=?, ~unit=?, ~roundingMethod=?, dateToCompare, date) =>
  internal_formatDistanceStrict(dateToCompare, date, {
    "addSuffix": addSuffix |> handleOptBool,
    "unit": unit
      |> Js.Option.map([@bs] unit => timeUnitToString(unit))
      |> Js.Nullable.fromOption,
    "roundingMethod": roundingMethod
      |> Js.Option.map([@bs] roundingMethod => partialMethodToString(roundingMethod))
      |> Js.Nullable.fromOption
  });
type formatDistanceToNowOptions = {.
  "includeSeconds": Js.Nullable.t(bool),
  "addSuffix": Js.Nullable.t(bool)
};
[@bs.module] external internal_formatDistanceToNow : (Js.Date.t, formatDistanceToNowOptions) => string = "date-fns/formatDistanceToNow";
let formatDistanceToNow = (~includeSeconds=?, ~addSuffix=?, date) =>
  internal_formatDistanceToNow(date, {
    "includeSeconds": includeSeconds |> handleOptBool,
    "addSuffix": addSuffix |> handleOptBool
  });

[@bs.module] external internal_format : (Js.Date.t, string) => string = "date-fns/format";
let format = flip(internal_format);

[@bs.module] external fromUnixTime: (int) => Js.Date.t = "date-fns/fromUnixTime";

[@bs.module] external internalIsAfter : (Js.Date.t, Js.Date.t) => bool = "date-fns/isAfter";
let isAfter = flip(internalIsAfter);
[@bs.module] external internalIsBefore : (Js.Date.t, Js.Date.t) => bool = "date-fns/isBefore";
let isBefore = flip(internalIsBefore);
[@bs.module] external isEqual : (Js.Date.t, Js.Date.t) => bool = "date-fns/isEqual";
[@bs.module] external isFuture : Js.Date.t => bool = "date-fns/isFuture";
[@bs.module] external isPast : Js.Date.t => bool = "date-fns/isPast";
[@bs.module] external isValid : Js.Date.t => bool = "date-fns/isValid";
[@bs.module] [@bs.splice] external max : array(Js.Date.t) => Js.Date.t = "date-fns/max";
[@bs.module] [@bs.splice] external min : array(Js.Date.t) => Js.Date.t = "date-fns/min";
type parseOptions = {.
  "additionalDigits": Js.Nullable.t(int)
};
[@bs.module] external internal_parseFloat : float => parseOptions => Js.Date.t = "date-fns/parse";
let parseFloat = (~additionalDigits=?, float) => internal_parseFloat(float, {
  "additionalDigits": additionalDigits |> Js.Nullable.fromOption
});
[@bs.module] external internal_parseString : string => parseOptions => Js.Date.t = "date-fns/parse";
let parseString = (~additionalDigits=?, string) => internal_parseString(string, {
  "additionalDigits": additionalDigits |> Js.Nullable.fromOption
});
[@bs.module] external areIntervalsOverlapping : (Js.Date.t, Js.Date.t, Js.Date.t, Js.Date.t) => bool = "date-fns/areIntervalsOverlapping";
[@bs.module] external getOverlappingDaysInIntervals : (Js.Date.t, Js.Date.t, Js.Date.t, Js.Date.t) => float = "date-fns/getOverlappingDaysInIntervals";
[@bs.module] external internalIsWithinRange : (Js.Date.t, Js.Date.t, Js.Date.t) => bool = "date-fns/isWithinInterval";
let isWithinInterval = (startDate, endDate, date) => internalIsWithinRange(date, startDate, endDate);

[@bs.module] external getTime : Js.Date.t => float = "date-fns/getTime";
[@bs.module] external getMilliseconds : (Js.Date.t) => float = "date-fns/getMilliseconds";
[@bs.module] external getSeconds : (Js.Date.t) => float = "date-fns/getSeconds";
[@bs.module] external getMinutes : (Js.Date.t) => float = "date-fns/getMinutes";
[@bs.module] external getHours : (Js.Date.t) => float = "date-fns/getHours";
[@bs.module] external getDate : (Js.Date.t) => float = "date-fns/getDate";
[@bs.module] external getDayOfYear : (Js.Date.t) => float = "date-fns/getDayOfYear";
[@bs.module] external getDay : (Js.Date.t) => float = "date-fns/getDay";
[@bs.module] external getISODay : (Js.Date.t) => float = "date-fns/getISODay";
[@bs.module] external getISOWeek : (Js.Date.t) => float = "date-fns/getISOWeek";
[@bs.module] external getDaysInMonth : (Js.Date.t) => float = "date-fns/getDaysInMonth";
[@bs.module] external getMonth : (Js.Date.t) => float = "date-fns/getMonth";
[@bs.module] external getQuarter : (Js.Date.t) => float = "date-fns/getQuarter";
[@bs.module] external getDaysInYear : (Js.Date.t) => float = "date-fns/getDaysInYear";
[@bs.module] external getYear : (Js.Date.t) => float = "date-fns/getYear";
[@bs.module] external getWeek : (Js.Date.t) => float = "date-fns/getWeek";
[@bs.module] external getWeekYear : (Js.Date.t) => float = "date-fns/getWeekYear";
[@bs.module] external startOfWeekYear : (Js.Date.t) => float = "date-fns/startOfWeekYear";
[@bs.module] external getISOWeeksInYear : (Js.Date.t) => float = "date-fns/getISOWeeksInYear";
[@bs.module] external getISOWeekYear : (Js.Date.t) => float = "date-fns/getISOWeekYear";
[@bs.module] external getDecade : (Js.Date.t) => float = "date-fns/getDecade";
[@bs.module] external startOfDecade : (Js.Date.t) => float = "date-fns/startOfDecade";
[@bs.module] external endOfDecade : (Js.Date.t) => float = "date-fns/endOfDecade";
[@bs.module] external lastDayOfDecade : (Js.Date.t) => float = "date-fns/lastDayOfDecade";

[@bs.module] external internal_setMilliseconds : (Js.Date.t, float) => Js.Date.t = "date-fns/setMilliseconds";
[@bs.module] external internal_setSeconds : (Js.Date.t, float) => Js.Date.t = "date-fns/setSeconds";
[@bs.module] external internal_setMinutes : (Js.Date.t, float) => Js.Date.t = "date-fns/setMinutes";
[@bs.module] external internal_setHours : (Js.Date.t, float) => Js.Date.t = "date-fns/setHours";
[@bs.module] external internal_setDate : (Js.Date.t, float) => Js.Date.t = "date-fns/setDate";
[@bs.module] external internal_setDayOfYear : (Js.Date.t, float) => Js.Date.t = "date-fns/setDayOfYear";
[@bs.module] external internal_setDay : (Js.Date.t, float) => Js.Date.t = "date-fns/setDay";
[@bs.module] external internal_setISODay : (Js.Date.t, float) => Js.Date.t = "date-fns/setISODay";
[@bs.module] external internal_setISOWeek : (Js.Date.t, float) => Js.Date.t = "date-fns/setISOWeek";
[@bs.module] external internal_setMonth : (Js.Date.t, float) => Js.Date.t = "date-fns/setMonth";
[@bs.module] external internal_setQuarter : (Js.Date.t, float) => Js.Date.t = "date-fns/setQuarter";
[@bs.module] external internal_setYear : (Js.Date.t, float) => Js.Date.t = "date-fns/setYear";
[@bs.module] external internal_setWeek : (Js.Date.t, float) => Js.Date.t = "date-fns/setWeek";
[@bs.module] external internal_setWeekYear : (Js.Date.t, float) => Js.Date.t = "date-fns/setWeekYear";
[@bs.module] external internal_setISOWeekYear : (Js.Date.t, float) => Js.Date.t = "date-fns/setISOWeekYear";

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
let setWeek = flip(internal_setWeek);
let setWeekYear = flip(internal_setWeekYear);
let setISOWeekYear = flip(internal_setISOWeekYear);

[@bs.module] external internal_subMilliseconds : (Js.Date.t, float) => Js.Date.t = "date-fns/subMilliseconds";
[@bs.module] external internal_subSeconds : (Js.Date.t, float) => Js.Date.t = "date-fns/subSeconds";
[@bs.module] external internal_subMinutes : (Js.Date.t, float) => Js.Date.t = "date-fns/subMinutes";
[@bs.module] external internal_subHours : (Js.Date.t, float) => Js.Date.t = "date-fns/subHours";
[@bs.module] external internal_subDays : (Js.Date.t, float) => Js.Date.t = "date-fns/subDays";
[@bs.module] external internal_subWeeks : (Js.Date.t, float) => Js.Date.t = "date-fns/subWeeks";
[@bs.module] external internal_subMonths : (Js.Date.t, float) => Js.Date.t = "date-fns/subMonths";
[@bs.module] external internal_subQuarters : (Js.Date.t, float) => Js.Date.t = "date-fns/subQuarters";
[@bs.module] external internal_subYears : (Js.Date.t, float) => Js.Date.t = "date-fns/subYears";
[@bs.module] external internal_subISOWeekYears : (Js.Date.t, float) => Js.Date.t = "date-fns/subISOWeekYears";

let subMilliseconds = flip(internal_subMilliseconds);
let subSeconds = flip(internal_subSeconds);
let subMinutes = flip(internal_subMinutes);
let subHours = flip(internal_subHours);
let subDays = flip(internal_subDays);
let subWeeks = flip(internal_subWeeks);
let subMonths = flip(internal_subMonths);
let subQuarters = flip(internal_subQuarters);
let subYears = flip(internal_subYears);
let subISOWeekYears = flip(internal_subISOWeekYears);

[@bs.module]
external internal_addBusinessDays: (Js.Date.t, int) => Js.Date.t =
  "date-fns/addBusinessDays";
[@bs.module] external internal_addMilliseconds : (Js.Date.t, float) => Js.Date.t = "date-fns/addMilliseconds";
[@bs.module] external internal_addSeconds : (Js.Date.t, float) => Js.Date.t = "date-fns/addSeconds";
[@bs.module] external internal_addMinutes : (Js.Date.t, float) => Js.Date.t = "date-fns/addMinutes";
[@bs.module] external internal_addHours : (Js.Date.t, float) => Js.Date.t = "date-fns/addHours";
[@bs.module] external internal_addDays : (Js.Date.t, float) => Js.Date.t = "date-fns/addDays";
[@bs.module] external internal_addWeeks : (Js.Date.t, float) => Js.Date.t = "date-fns/addWeeks";
[@bs.module] external internal_addMonths : (Js.Date.t, float) => Js.Date.t = "date-fns/addMonths";
[@bs.module] external internal_addQuarters : (Js.Date.t, float) => Js.Date.t = "date-fns/addQuarters";
[@bs.module] external internal_addYears : (Js.Date.t, float) => Js.Date.t = "date-fns/addYears";
[@bs.module] external internal_addISOWeekYears : (Js.Date.t, float) => Js.Date.t = "date-fns/addISOWeekYears";

let addBusinessDays = flip(internal_addBusinessDays);
let addMilliseconds = flip(internal_addMilliseconds);
let addSeconds = flip(internal_addSeconds);
let addMinutes = flip(internal_addMinutes);
let addHours = flip(internal_addHours);
let addDays = flip(internal_addDays);
let addWeeks = flip(internal_addWeeks);
let addMonths = flip(internal_addMonths);
let addQuarters = flip(internal_addQuarters);
let addYears = flip(internal_addYears);
let addISOWeekYears = flip(internal_addISOWeekYears);

[@bs.module] external isThisSecond : Js.Date.t => bool = "date-fns/isThisSecond";
[@bs.module] external isThisMinute : Js.Date.t => bool = "date-fns/isThisMinute";
[@bs.module] external isThisHour : Js.Date.t => bool = "date-fns/isThisHour";
[@bs.module] external isToday : Js.Date.t => bool = "date-fns/isToday";
[@bs.module] external isYesterday : Js.Date.t => bool = "date-fns/isYesterday";
[@bs.module] external isTomorrow : Js.Date.t => bool = "date-fns/isTomorrow";
[@bs.module] external isThisWeek : Js.Date.t => bool = "date-fns/isThisWeek";
[@bs.module] external isThisISOWeek : Js.Date.t => bool = "date-fns/isThisISOWeek";
[@bs.module] external isThisMonth : Js.Date.t => bool = "date-fns/isThisMonth";
[@bs.module] external isThisQuarter : Js.Date.t => bool = "date-fns/isThisQuarter";
[@bs.module] external isThisYear : Js.Date.t => bool = "date-fns/isThisYear";
[@bs.module] external isThisISOYear : Js.Date.t => bool = "date-fns/isThisISOYear";

[@bs.module] external isSameSecond : (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameSecond";
[@bs.module] external isSameMinute : (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameMinute";
[@bs.module] external isSameHour : (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameHour";
[@bs.module] external isSameDay : (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameDay";
[@bs.module] external isSameWeek : (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameWeek";
[@bs.module] external isSameISOWeek : (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameISOWeek";
[@bs.module] external isSameMonth : (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameMonth";
[@bs.module] external isSameQuarter : (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameQuarter";
[@bs.module] external isSameYear : (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameYear";
[@bs.module] external isSameISOYear : (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameISOYear";

[@bs.module] external isMonday : Js.Date.t => bool = "date-fns/isMonday";
[@bs.module] external isTuesday : Js.Date.t => bool = "date-fns/isTuesday";
[@bs.module] external isWednesday : Js.Date.t => bool = "date-fns/isWednesday";
[@bs.module] external isThursday : Js.Date.t => bool = "date-fns/isThursday";
[@bs.module] external isFriday : Js.Date.t => bool = "date-fns/isFriday";
[@bs.module] external isSaturday : Js.Date.t => bool = "date-fns/isSaturday";
[@bs.module] external isSunday : Js.Date.t => bool = "date-fns/isSunday";
[@bs.module] external isWeekend : Js.Date.t => bool = "date-fns/isWeekend";

[@bs.module] external differenceInMilliseconds : (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInMilliseconds";
[@bs.module] external differenceInSeconds : (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInSeconds";
[@bs.module] external differenceInMinutes : (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInMinutes";
[@bs.module] external differenceInHours : (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInHours";
[@bs.module] external differenceInCalendarDays : (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInCalendarDays";
[@bs.module] external differenceInDays : (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInDays";
[@bs.module] external differenceInCalendarWeeks : (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInCalendarWeeks";
[@bs.module] external differenceInWeeks : (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInWeeks";
[@bs.module] external differenceInCalendarISOWeeks : (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInCalendarISOWeeks";
[@bs.module] external differenceInCalendarMonths : (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInCalendarMonths";
[@bs.module] external differenceInMonths : (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInMonths";
[@bs.module] external differenceInCalendarQuarters : (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInCalendarQuarters";
[@bs.module] external differenceInQuarters : (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInQuarters";
[@bs.module] external differenceInYears : (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInYears";
[@bs.module] external differenceInISOYears : (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInISOYears";
[@bs.module] external differenceInCalendarYears : (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInCalendarYears";
[@bs.module] external differenceInCalendarISOYears : (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInCalendarISOYears";

[@bs.module] external startOfSecond : Js.Date.t => Js.Date.t = "date-fns/startOfSecond";
[@bs.module] external endOfSecond : Js.Date.t => Js.Date.t = "date-fns/endOfSecond";
[@bs.module] external startOfMinute : Js.Date.t => Js.Date.t = "date-fns/startOfMinute";
[@bs.module] external endOfMinute : Js.Date.t => Js.Date.t = "date-fns/endOfMinute";
[@bs.module] external startOfHour : Js.Date.t => Js.Date.t = "date-fns/startOfHour";
[@bs.module] external endOfHour : Js.Date.t => Js.Date.t = "date-fns/endOfHour";
[@bs.module] external startOfDay : Js.Date.t => Js.Date.t = "date-fns/startOfDay";
[@bs.module] external endOfDay : Js.Date.t => Js.Date.t = "date-fns/endOfDay";
[@bs.module] external startOfWeek : Js.Date.t => Js.Date.t = "date-fns/startOfWeek";
[@bs.module] external endOfWeek : Js.Date.t => Js.Date.t = "date-fns/endOfWeek";
[@bs.module] external startOfISOWeek : Js.Date.t => Js.Date.t = "date-fns/startOfISOWeek";
[@bs.module] external endOfISOWeek : Js.Date.t => Js.Date.t = "date-fns/endOfISOWeek";
[@bs.module] external startOfMonth : Js.Date.t => Js.Date.t = "date-fns/startOfMonth";
[@bs.module] external endOfMonth : Js.Date.t => Js.Date.t = "date-fns/endOfMonth";
[@bs.module] external startOfQuarter : Js.Date.t => Js.Date.t = "date-fns/startOfQuarter";
[@bs.module] external endOfQuarter : Js.Date.t => Js.Date.t = "date-fns/endOfQuarter";
[@bs.module] external startOfYear : Js.Date.t => Js.Date.t = "date-fns/startOfYear";
[@bs.module] external endOfYear : Js.Date.t => Js.Date.t = "date-fns/endOfYear";
[@bs.module] external startOfISOYear : Js.Date.t => Js.Date.t = "date-fns/startOfISOYear";
[@bs.module] external endOfISOYear : Js.Date.t => Js.Date.t = "date-fns/endOfISOYear";

[@bs.module] external lastDayOfWeek : Js.Date.t => Js.Date.t = "date-fns/lastDayOfWeek";
[@bs.module] external lastDayOfISOWeek : Js.Date.t => Js.Date.t = "date-fns/lastDayOfISOWeek";
[@bs.module] external lastDayOfMonth : Js.Date.t => Js.Date.t = "date-fns/lastDayOfMonth";
[@bs.module] external lastDayOfQuarter : Js.Date.t => Js.Date.t = "date-fns/lastDayOfQuarter";
[@bs.module] external lastDayOfYear : Js.Date.t => Js.Date.t = "date-fns/lastDayOfYear";
[@bs.module] external lastDayOfISOYear : Js.Date.t => Js.Date.t = "date-fns/lastDayOfISOYear";

[@bs.module] external startOfYesterday : unit => Js.Date.t = "date-fns/startOfYesterday";
[@bs.module] external endOfYesterday : unit => Js.Date.t = "date-fns/endOfYesterday";
[@bs.module] external startOfToday : unit => Js.Date.t = "date-fns/startOfToday";
[@bs.module] external endOfToday : unit => Js.Date.t = "date-fns/endOfToday";
[@bs.module] external startOfTomorrow : unit => Js.Date.t = "date-fns/startOfTomorrow";
[@bs.module] external endOfTomorrow : unit => Js.Date.t = "date-fns/endOfTomorrow";

[@bs.module] external isFirstDayOfMonth : Js.Date.t => bool = "date-fns/isFirstDayOfMonth";
[@bs.module] external isLastDayOfMonth : Js.Date.t => bool = "date-fns/isLastDayOfMonth";
[@bs.module] external isLeapYear : Js.Date.t => bool = "date-fns/isLeapYear";

[@bs.module] external eachDayOfInterval : (Js.Date.t, Js.Date.t) => array(Js.Date.t) = "date-fns/eachDayOfInterval";
[@bs.module] external eachWeekOfInterval : (Js.Date.t, Js.Date.t) => array(Js.Date.t) = "date-fns/eachWeekOfInterval";
