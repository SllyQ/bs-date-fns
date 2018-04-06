let flip = (f) => (a, b) => f(b, a);
let handleOptBool = optBool => optBool
  |> Js.Option.map([@bs] bool => bool ? Js.true_ : Js.false_)
  |> Js.Nullable.fromOption;

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

[@bs.module] external internal_closestIndexTo : (Js.Date.t, array(Js.Date.t)) => int = "date-fns/closest_index_to";
let closestIndexTo = flip(internal_closestIndexTo);
[@bs.module] external internal_closestTo : (Js.Date.t, array(Js.Date.t)) => Js.Date.t = "date-fns/closest_to";
let closestTo = flip(internal_closestTo);
[@bs.module] external compareAsc : (Js.Date.t, Js.Date.t) => int = "date-fns/compare_asc";
[@bs.module] external compareDesc : (Js.Date.t, Js.Date.t) => int = "date-fns/compare_desc";
type distanceInWordsOptions = {.
  "includeSeconds": Js.Nullable.t(Js.boolean),
  "addSuffix": Js.Nullable.t(Js.boolean),
};
[@bs.module] external internal_distanceInWords : (Js.Date.t, Js.Date.t, distanceInWordsOptions) => string = "date-fns/distance_in_words";
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
[@bs.module] external internal_distanceInWordsStrict : (Js.Date.t, Js.Date.t, distanceInWordsStrictOptions) => string = "date-fns/distance_in_words_strict";
let distanceInWordsStrict = (~addSuffix=?, ~unit=?, ~partialMethod=?, dateToCompare, date) =>
  internal_distanceInWordsStrict(dateToCompare, date, {
    "addSuffix": addSuffix |> handleOptBool,
    "unit": unit
      |> Js.Option.map([@bs] unit => timeUnitToString(unit))
      |> Js.Nullable.fromOption,
    "partialMethod": partialMethod
      |> Js.Option.map([@bs] partialMethod => partialMethodToString(partialMethod))
      |> Js.Nullable.fromOption
  });
type distanceInWordsToNowOptions = {.
  "includeSeconds": Js.Nullable.t(Js.boolean),
  "addSuffix": Js.Nullable.t(Js.boolean)
};
[@bs.module] external internal_distanceInWordsToNow : (Js.Date.t, distanceInWordsToNowOptions) => string = "date-fns/distance_in_words_to_now";
let distanceInWordsToNow = (~includeSeconds=?, ~addSuffix=?, date) =>
  internal_distanceInWordsToNow(date, {
    "includeSeconds": includeSeconds |> handleOptBool,
    "addSuffix": addSuffix |> handleOptBool
  });

[@bs.module] external internal_format : (Js.Date.t, string) => string = "date-fns/format";
let format = flip(internal_format);
[@bs.module] external internal_isAfter : (Js.Date.t, Js.Date.t) => bool = "date-fns/is_after";
let isAfter = flip(internal_isAfter);
[@bs.module] external internal_isBefore : (Js.Date.t, Js.Date.t) => bool = "date-fns/is_before";
let isBefore = flip(internal_isBefore);
[@bs.module] external isEqual : (Js.Date.t, Js.Date.t) => bool = "date-fns/is_equal";
[@bs.module] external isFuture : Js.Date.t => bool = "date-fns/is_future";
[@bs.module] external isPast : Js.Date.t => bool = "date-fns/is_past";
[@bs.module] external isValid : Js.Date.t => bool = "date-fns/is_valid";
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
[@bs.module] external areRangesOverlapping : (Js.Date.t, Js.Date.t, Js.Date.t, Js.Date.t) => bool = "date-fns/are_ranges_overlapping";
[@bs.module] external getOverlappingDaysInRanges : (Js.Date.t, Js.Date.t, Js.Date.t, Js.Date.t) => float = "date-fns/get_overlapping_days_in_ranges";
[@bs.module] external internal_isWithinRange : (Js.Date.t, Js.Date.t, Js.Date.t) => bool = "date-fns/is_within_range";
let isWithinRange = (startDate, endDate, date) => internal_isWithinRange(date, startDate, endDate);

[@bs.module] external getTime : Js.Date.t => float = "date-fns/get_time";
[@bs.module] external getMilliseconds : (Js.Date.t) => float = "date-fns/get_milliseconds";
[@bs.module] external getSeconds : (Js.Date.t) => float = "date-fns/get_seconds";
[@bs.module] external getMinutes : (Js.Date.t) => float = "date-fns/get_minutes";
[@bs.module] external getHours : (Js.Date.t) => float = "date-fns/get_hours";
[@bs.module] external getDate : (Js.Date.t) => float = "date-fns/get_date";
[@bs.module] external getDayOfYear : (Js.Date.t) => float = "date-fns/get_day_of_year";
[@bs.module] external getDay : (Js.Date.t) => float = "date-fns/get_day";
[@bs.module] external getISODay : (Js.Date.t) => float = "date-fns/get_iso_day";
[@bs.module] external getISOWeek : (Js.Date.t) => float = "date-fns/get_iso_week";
[@bs.module] external getDaysInMonth : (Js.Date.t) => float = "date-fns/get_days_in_month";
[@bs.module] external getMonth : (Js.Date.t) => float = "date-fns/get_month";
[@bs.module] external getQuarter : (Js.Date.t) => float = "date-fns/get_quarter";
[@bs.module] external getDaysInYear : (Js.Date.t) => float = "date-fns/get_days_in_year";
[@bs.module] external getYear : (Js.Date.t) => float = "date-fns/get_year";
[@bs.module] external getISOWeeksInYear : (Js.Date.t) => float = "date-fns/get_iso_weeks_in_year";
[@bs.module] external getISOYear : (Js.Date.t) => float = "date-fns/get_iso_year";

[@bs.module] external internal_setMilliseconds : (Js.Date.t, float) => Js.Date.t = "date-fns/set_milliseconds";
[@bs.module] external internal_setSeconds : (Js.Date.t, float) => Js.Date.t = "date-fns/set_seconds";
[@bs.module] external internal_setMinutes : (Js.Date.t, float) => Js.Date.t = "date-fns/set_minutes";
[@bs.module] external internal_setHours : (Js.Date.t, float) => Js.Date.t = "date-fns/set_hours";
[@bs.module] external internal_setDate : (Js.Date.t, float) => Js.Date.t = "date-fns/set_date";
[@bs.module] external internal_setDayOfYear : (Js.Date.t, float) => Js.Date.t = "date-fns/set_day_of_year";
[@bs.module] external internal_setDay : (Js.Date.t, float) => Js.Date.t = "date-fns/set_day";
[@bs.module] external internal_setISODay : (Js.Date.t, float) => Js.Date.t = "date-fns/set_iso_day";
[@bs.module] external internal_setISOWeek : (Js.Date.t, float) => Js.Date.t = "date-fns/set_iso_week";
[@bs.module] external internal_setMonth : (Js.Date.t, float) => Js.Date.t = "date-fns/set_month";
[@bs.module] external internal_setQuarter : (Js.Date.t, float) => Js.Date.t = "date-fns/set_quarter";
[@bs.module] external internal_setYear : (Js.Date.t, float) => Js.Date.t = "date-fns/set_year";
[@bs.module] external internal_setISOYear : (Js.Date.t, float) => Js.Date.t = "date-fns/set_iso_year";

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

[@bs.module] external internal_subMilliseconds : (Js.Date.t, float) => Js.Date.t = "date-fns/sub_milliseconds";
[@bs.module] external internal_subSeconds : (Js.Date.t, float) => Js.Date.t = "date-fns/sub_seconds";
[@bs.module] external internal_subMinutes : (Js.Date.t, float) => Js.Date.t = "date-fns/sub_minutes";
[@bs.module] external internal_subHours : (Js.Date.t, float) => Js.Date.t = "date-fns/sub_hours";
[@bs.module] external internal_subDays : (Js.Date.t, float) => Js.Date.t = "date-fns/sub_days";
[@bs.module] external internal_subWeeks : (Js.Date.t, float) => Js.Date.t = "date-fns/sub_weeks";
[@bs.module] external internal_subMonths : (Js.Date.t, float) => Js.Date.t = "date-fns/sub_months";
[@bs.module] external internal_subQuarters : (Js.Date.t, float) => Js.Date.t = "date-fns/sub_quarters";
[@bs.module] external internal_subYears : (Js.Date.t, float) => Js.Date.t = "date-fns/sub_years";
[@bs.module] external internal_subISOYears : (Js.Date.t, float) => Js.Date.t = "date-fns/sub_iso_years";

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

[@bs.module] external internal_addMilliseconds : (Js.Date.t, float) => Js.Date.t = "date-fns/add_milliseconds";
[@bs.module] external internal_addSeconds : (Js.Date.t, float) => Js.Date.t = "date-fns/add_seconds";
[@bs.module] external internal_addMinutes : (Js.Date.t, float) => Js.Date.t = "date-fns/add_minutes";
[@bs.module] external internal_addHours : (Js.Date.t, float) => Js.Date.t = "date-fns/add_hours";
[@bs.module] external internal_addDays : (Js.Date.t, float) => Js.Date.t = "date-fns/add_days";
[@bs.module] external internal_addWeeks : (Js.Date.t, float) => Js.Date.t = "date-fns/add_weeks";
[@bs.module] external internal_addMonths : (Js.Date.t, float) => Js.Date.t = "date-fns/add_months";
[@bs.module] external internal_addQuarters : (Js.Date.t, float) => Js.Date.t = "date-fns/add_quarters";
[@bs.module] external internal_addYears : (Js.Date.t, float) => Js.Date.t = "date-fns/add_years";
[@bs.module] external internal_addISOYears : (Js.Date.t, float) => Js.Date.t = "date-fns/add_iso_years";

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

[@bs.module] external isThisSecond : Js.Date.t => bool = "date-fns/is_this_second";
[@bs.module] external isThisMinute : Js.Date.t => bool = "date-fns/is_this_minute";
[@bs.module] external isThisHour : Js.Date.t => bool = "date-fns/is_this_hour";
[@bs.module] external isToday : Js.Date.t => bool = "date-fns/is_today";
[@bs.module] external isYesterday : Js.Date.t => bool = "date-fns/is_yesterday";
[@bs.module] external isTomorrow : Js.Date.t => bool = "date-fns/is_tomorrow";
[@bs.module] external isThisWeek : Js.Date.t => bool = "date-fns/is_this_week";
[@bs.module] external isThisISOWeek : Js.Date.t => bool = "date-fns/is_this_iso_week";
[@bs.module] external isThisMonth : Js.Date.t => bool = "date-fns/is_this_month";
[@bs.module] external isThisQuarter : Js.Date.t => bool = "date-fns/is_this_quarter";
[@bs.module] external isThisYear : Js.Date.t => bool = "date-fns/is_this_year";
[@bs.module] external isThisISOYear : Js.Date.t => bool = "date-fns/is_this_iso_year";

[@bs.module] external isSameSecond : (Js.Date.t, Js.Date.t) => bool = "date-fns/is_same_second";
[@bs.module] external isSameMinute : (Js.Date.t, Js.Date.t) => bool = "date-fns/is_same_minute";
[@bs.module] external isSameHour : (Js.Date.t, Js.Date.t) => bool = "date-fns/is_same_hour";
[@bs.module] external isSameDay : (Js.Date.t, Js.Date.t) => bool = "date-fns/is_same_day";
[@bs.module] external isSameWeek : (Js.Date.t, Js.Date.t) => bool = "date-fns/is_same_week";
[@bs.module] external isSameISOWeek : (Js.Date.t, Js.Date.t) => bool = "date-fns/is_same_iso_week";
[@bs.module] external isSameMonth : (Js.Date.t, Js.Date.t) => bool = "date-fns/is_same_month";
[@bs.module] external isSameQuarter : (Js.Date.t, Js.Date.t) => bool = "date-fns/is_same_quarter";
[@bs.module] external isSameYear : (Js.Date.t, Js.Date.t) => bool = "date-fns/is_same_year";
[@bs.module] external isSameISOYear : (Js.Date.t, Js.Date.t) => bool = "date-fns/is_same_iso_year";

[@bs.module] external isMonday : Js.Date.t => bool = "date-fns/is_monday";
[@bs.module] external isTuesday : Js.Date.t => bool = "date-fns/is_tuesday";
[@bs.module] external isWednesday : Js.Date.t => bool = "date-fns/is_wednesday";
[@bs.module] external isThursday : Js.Date.t => bool = "date-fns/is_thursday";
[@bs.module] external isFriday : Js.Date.t => bool = "date-fns/is_friday";
[@bs.module] external isSaturday : Js.Date.t => bool = "date-fns/is_saturday";
[@bs.module] external isSunday : Js.Date.t => bool = "date-fns/is_sunday";
[@bs.module] external isWeekend : Js.Date.t => bool = "date-fns/is_weekend";

[@bs.module] external differenceInMilliseconds : (Js.Date.t, Js.Date.t) => float = "date-fns/difference_in_milliseconds";
[@bs.module] external differenceInSeconds : (Js.Date.t, Js.Date.t) => float = "date-fns/difference_in_seconds";
[@bs.module] external differenceInMinutes : (Js.Date.t, Js.Date.t) => float = "date-fns/difference_in_minutes";
[@bs.module] external differenceInHours : (Js.Date.t, Js.Date.t) => float = "date-fns/difference_in_hours";
[@bs.module] external differenceInCalendarDays : (Js.Date.t, Js.Date.t) => float = "date-fns/difference_in_calendar_days";
[@bs.module] external differenceInDays : (Js.Date.t, Js.Date.t) => float = "date-fns/difference_in_days";
[@bs.module] external differenceInCalendarWeeks : (Js.Date.t, Js.Date.t) => float = "date-fns/difference_in_calendar_weeks";
[@bs.module] external differenceInWeeks : (Js.Date.t, Js.Date.t) => float = "date-fns/difference_in_weeks";
[@bs.module] external differenceInCalendarISOWeeks : (Js.Date.t, Js.Date.t) => float = "date-fns/difference_in_calendar_iso_weeks";
[@bs.module] external differenceInCalendarMonths : (Js.Date.t, Js.Date.t) => float = "date-fns/difference_in_calendar_months";
[@bs.module] external differenceInMonths : (Js.Date.t, Js.Date.t) => float = "date-fns/difference_in_months";
[@bs.module] external differenceInCalendarQuarters : (Js.Date.t, Js.Date.t) => float = "date-fns/difference_in_calendar_quarters";
[@bs.module] external differenceInQuarters : (Js.Date.t, Js.Date.t) => float = "date-fns/difference_in_quarters";
[@bs.module] external differenceInYears : (Js.Date.t, Js.Date.t) => float = "date-fns/difference_in_years";
[@bs.module] external differenceInISOYears : (Js.Date.t, Js.Date.t) => float = "date-fns/difference_in_iso_years";
[@bs.module] external differenceInCalendarYears : (Js.Date.t, Js.Date.t) => float = "date-fns/difference_in_calendar_years";
[@bs.module] external differenceInCalendarISOYears : (Js.Date.t, Js.Date.t) => float = "date-fns/difference_in_calendar_iso_years";

[@bs.module] external startOfSecond : Js.Date.t => Js.Date.t = "date-fns/start_of_second";
[@bs.module] external endOfSecond : Js.Date.t => Js.Date.t = "date-fns/end_of_second";
[@bs.module] external startOfMinute : Js.Date.t => Js.Date.t = "date-fns/start_of_minute";
[@bs.module] external endOfMinute : Js.Date.t => Js.Date.t = "date-fns/end_of_minute";
[@bs.module] external startOfHour : Js.Date.t => Js.Date.t = "date-fns/start_of_hour";
[@bs.module] external endOfHour : Js.Date.t => Js.Date.t = "date-fns/end_of_hour";
[@bs.module] external startOfDay : Js.Date.t => Js.Date.t = "date-fns/start_of_day";
[@bs.module] external endOfDay : Js.Date.t => Js.Date.t = "date-fns/end_of_day";
[@bs.module] external startOfWeek : Js.Date.t => Js.Date.t = "date-fns/start_of_week";
[@bs.module] external endOfWeek : Js.Date.t => Js.Date.t = "date-fns/end_of_week";
[@bs.module] external startOfISOWeek : Js.Date.t => Js.Date.t = "date-fns/start_of_iso_week";
[@bs.module] external endOfISOWeek : Js.Date.t => Js.Date.t = "date-fns/end_of_iso_week";
[@bs.module] external startOfMonth : Js.Date.t => Js.Date.t = "date-fns/start_of_month";
[@bs.module] external endOfMonth : Js.Date.t => Js.Date.t = "date-fns/end_of_month";
[@bs.module] external startOfQuarter : Js.Date.t => Js.Date.t = "date-fns/start_of_quarter";
[@bs.module] external endOfQuarter : Js.Date.t => Js.Date.t = "date-fns/end_of_quarter";
[@bs.module] external startOfYear : Js.Date.t => Js.Date.t = "date-fns/start_of_year";
[@bs.module] external endOfYear : Js.Date.t => Js.Date.t = "date-fns/end_of_year";
[@bs.module] external startOfISOYear : Js.Date.t => Js.Date.t = "date-fns/start_of_iso_year";
[@bs.module] external endOfISOYear : Js.Date.t => Js.Date.t = "date-fns/end_of_iso_year";

[@bs.module] external lastDayOfWeek : Js.Date.t => Js.Date.t = "date-fns/last_day_of_week";
[@bs.module] external lastDayOfISOWeek : Js.Date.t => Js.Date.t = "date-fns/last_day_of_iso_week";
[@bs.module] external lastDayOfMonth : Js.Date.t => Js.Date.t = "date-fns/last_day_of_month";
[@bs.module] external lastDayOfQuarter : Js.Date.t => Js.Date.t = "date-fns/last_day_of_quarter";
[@bs.module] external lastDayOfYear : Js.Date.t => Js.Date.t = "date-fns/last_day_of_year";
[@bs.module] external lastDayOfISOYear : Js.Date.t => Js.Date.t = "date-fns/last_day_of_iso_year";

[@bs.module] external startOfYesterday : unit => Js.Date.t = "date-fns/start_of_yesterday";
[@bs.module] external endOfYesterday : unit => Js.Date.t = "date-fns/end_of_yesterday";
[@bs.module] external startOfToday : unit => Js.Date.t = "date-fns/start_of_today";
[@bs.module] external endOfToday : unit => Js.Date.t = "date-fns/end_of_today";
[@bs.module] external startOfTomorrow : unit => Js.Date.t = "date-fns/start_of_tomorrow";
[@bs.module] external endOfTomorrow : unit => Js.Date.t = "date-fns/end_of_tomorrow";

[@bs.module] external isFirstDayOfMonth : Js.Date.t => bool = "date-fns/is_first_day_of_month";
[@bs.module] external isLastDayOfMonth : Js.Date.t => bool = "date-fns/is_last_day_of_month";
[@bs.module] external isLeapYear : Js.Date.t => bool = "date-fns/is_leap_year";

[@bs.module] external eachDay : (Js.Date.t, Js.Date.t) => array(Js.Date.t) = "date-fns/each_day";
