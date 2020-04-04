type interval = {
  start: Js.Date.t,
  [@bs.as "end"]
  end_: Js.Date.t,
};

type locale;

// Common Helpers
[@bs.module "date-fns/closestIndexTo"]
external closestIndexTo: (Js.Date.t, array(Js.Date.t)) => int = "default";
[@bs.module "date-fns/closestTo"]
external closestTo: (Js.Date.t, array(Js.Date.t)) => Js.Date.t = "default";
[@bs.module "date-fns/compareAsc"] external compareAsc: (Js.Date.t, Js.Date.t) => int = "default";
[@bs.module "date-fns/compareDesc"] external compareDesc: (Js.Date.t, Js.Date.t) => int = "default";

[@bs.module "date-fns/format"] external format: (Js.Date.t, string) => string = "default";
type formatOptions = {
  locale: option(locale),
  weekStartsOn: option(int),
  firstWeekContainsDate: option(int),
  useAdditionalWeekYearTokens: option(bool),
  useAdditionalDayOfYearTokens: option(bool),
};
[@bs.module "date-fns/format"] external formatOpt: (Js.Date.t, string, formatOptions) => string = "default";
[@bs.module "date-fns/formatDistance"] external formatDistance: (Js.Date.t, Js.Date.t) => string = "default";
type formatDistanceOptions = {
  includeSeconds: option(bool),
  addSuffix: option(bool),
  locale: option(locale),
};
[@bs.module "date-fns/formatDistance"]
external formatDistanceOpt: (Js.Date.t, Js.Date.t, formatDistanceOptions) => string =
  "default";
[@bs.module "date-fns/formatDistanceStrict"]
external formatDistanceStrict: (Js.Date.t, Js.Date.t) => string = "default";
type formatDistanceStrictOptions = {
  addSuffix: option(bool),
  unit: option(string),
  roundingMethod: option(string),
  locale: option(locale),
};
[@bs.module "date-fns/formatDistanceStrict"]
external formatDistanceStrictOpt: (Js.Date.t, Js.Date.t, formatDistanceStrictOptions) => string =
  "default";
[@bs.module "date-fns/formatDistanceToNow"] external formatDistanceToNow: Js.Date.t => string = "default";
type formatDistanceToNowOptions = {
  includeSeconds: option(bool),
  addSuffix: option(bool),
  locale: option(locale),
};
[@bs.module "date-fns/formatDistanceToNow"]
external formatDistanceToNowOpt: (Js.Date.t, formatDistanceToNowOptions) => string =
  "default";
external formatISO: Js.Date.t => string = "date-fns/formatISO";
type formatISOOptions = {
  format: option(string),
  representation: option(string),
};
external formatISOOpt: (Js.Date.t, formatISOOptions) => string = "date-fns/formatISO";
external formatISO9075: Js.Date.t => string = "date-fns/formatISO9075";
type formatISO9075Options = {
  format: option(string),
  representation: option(string),
};
external formatISO9075Opt: (Js.Date.t, formatISO9075Options) => string = "date-fns/formatISO9075";

[@bs.module "date-fns/formatRFC3339"] external formatRFC3339: Js.Date.t => string = "default";
type formatRFC3339Options = {fractionDigits: option(int)};
[@bs.module "date-fns/formatRFC3339"]
external formatRFC3339Options: (Js.Date.t, formatRFC3339Options) => string =
  "default";
[@bs.module "date-fns/formatRFC7231"] external formatRFC7231: Js.Date.t => string = "default";
[@bs.module "date-fns/formatRelative"] external formatRelative: (Js.Date.t, Js.Date.t) => string = "default";
type formatRelativeOptions = {
  locale: option(locale),
  weekStartsOn: option(int),
};
[@bs.module "date-fns/formatRelative"]
external formatRelativeOpt: (Js.Date.t, Js.Date.t, formatRelativeOptions) => string =
  "default";
[@bs.module "date-fns/isAfter"] external isAfter: (Js.Date.t, Js.Date.t) => bool = "default";
[@bs.module "date-fns/isBefore"] external isBefore: (Js.Date.t, Js.Date.t) => bool = "default";
[@bs.module "date-fns/isDate"] external isDate: 'a => bool = "default";
[@bs.module "date-fns/isEqual"] external isEqual: (Js.Date.t, Js.Date.t) => bool = "default";
[@bs.module "date-fns/isFuture"] external isFuture: Js.Date.t => bool = "default";
[@bs.module "date-fns/isPast"] external isPast: Js.Date.t => bool = "default";
[@bs.module "date-fns/isValid"] external isValid: 'a => bool = "default";
[@bs.module "date-fns/lightFormat"] external lightFormat: (Js.Date.t, string) => string = "default";
[@bs.module "date-fns/max"] external max: array(Js.Date.t) => Js.Date.t = "default";
[@bs.module "date-fns/min"] external min: array(Js.Date.t) => Js.Date.t = "default";
[@bs.module "date-fns/parse"] external parse: (string, string, Js.Date.t) => Js.Date.t = "default";
type parseOptions = {
  locale: option(locale),
  weekStartsOn: option(int),
  firstWeekContainsDate: option(int),
  useAdditionalWeekYearTokens: option(bool),
  useAdditionalDayOfYearTokens: option(bool),
};
[@bs.module "date-fns/parse"]
external parseOpt: (string, string, Js.Date.t, parseOptions) => Js.Date.t = "default";
[@bs.module "date-fns/parseISO"] external parseISO: string => Js.Date.t = "default";
type parseISOOptions = {additionalDigits: option(int)};
[@bs.module "date-fns/parseISO"] external parseISOOpt: (string, parseISOOptions) => Js.Date.t = "default";
[@bs.module "date-fns/parseJSON"] external parseJSONString: string => Js.Date.t = "default";
[@bs.module "date-fns/parseJSON"] external parseJSONFloat: float => Js.Date.t = "default";
[@bs.module "date-fns/parseJSON"] external parseJSONInt: int => Js.Date.t = "default";
type setOptions = {
  year: option(int),
  month: option(int),
  date: option(int),
  hours: option(int),
  minutes: option(int),
  seconds: option(int),
  milliseconds: option(int),
};
[@bs.module "date-fns/set"] external set: (Js.Date.t, setOptions) => Js.Date.t = "default";
[@bs.module "date-fns/toDate"] external toDateFloat: float => Js.Date.t = "default";
[@bs.module "date-fns/toDate"] external toDateInt: int => Js.Date.t = "default";

// Interval Helpers
[@bs.module "date-fns/areIntervalsOverlapping"]
external areIntervalsOverlapping: (Js.Date.t, Js.Date.t) => bool =
  "default";
[@bs.module "date-fns/eachDayOfInterval"]
external eachDayOfInterval: interval => array(Js.Date.t) = "default";
type eachDayOfIntervalOptions = {step: option(int)};
[@bs.module "date-fns/eachDayOfInterval"]
external eachDayOfIntervalOpt: (interval, eachDayOfIntervalOptions) => array(Js.Date.t) =
  "default";
[@bs.module "date-fns/eachWeekOfInterval"]
external eachWeekOfInterval: interval => array(Js.Date.t) = "default";
type eachWeekOfIntervalOptions = {
  locale: option(locale),
  weekStartsOn: option(int),
};
[@bs.module "date-fns/eachWeekOfInterval"]
external eachWeekOfIntervalOpt: (interval, eachWeekOfIntervalOptions) => array(Js.Date.t) =
  "default";
[@bs.module "date-fns/eachWeekendOfInterval"]
external eachWeekendOfInterval: interval => array(Js.Date.t) = "default";
[@bs.module "date-fns/getOverlappingDaysInIntervals"]
external getOverlappingDaysInIntervals: (interval, interval) => int =
  "default";
[@bs.module "date-fns/getOverlappingDaysInIntervals"]
external getOverlappingDaysInIntervalsf: (interval, interval) => float =
  "default";
[@bs.module "date-fns/isWithinInterval"]
external isWithinInterval: (Js.Date.t, interval) => bool = "default";

// Timestamp Helpers
[@bs.module "date-fns/fromUnixTime"] external fromUnixTime: float => Js.Date.t = "default";
[@bs.module "date-fns/getTime"] external getTime: Js.Date.t => float = "default";
[@bs.module "date-fns/getUnixTime"] external getUnixTime: Js.Date.t => float = "default";

// Millisecond Helpers
[@bs.module "date-fns/addMilliseconds"] external addMilliseconds: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/addMilliseconds"]
external addMillisecondsf: (Js.Date.t, float) => Js.Date.t = "default";
[@bs.module "date-fns/differenceInMilliseconds"]
external differenceInMilliseconds: (Js.Date.t, Js.Date.t) => int =
  "default";
[@bs.module "date-fns/differenceInMilliseconds"]
external differenceInMillisecondsf: (Js.Date.t, Js.Date.t) => float =
  "default";
[@bs.module "date-fns/getMilliseconds"] external getMilliseconds: Js.Date.t => int = "default";
[@bs.module "date-fns/getMilliseconds"] external getMillisecondsf: Js.Date.t => float = "default";
[@bs.module "date-fns/setMilliseconds"] external setMilliseconds: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/setMilliseconds"]
external setMillisecondsf: (Js.Date.t, float) => Js.Date.t = "default";
[@bs.module "date-fns/subMilliseconds"] external subMilliseconds: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/subMilliseconds"]
external subMillisecondsf: (Js.Date.t, float) => Js.Date.t = "default";

// Second Helpers
[@bs.module "date-fns/addSeconds"] external addSeconds: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/addSeconds"] external addSecondsf: (Js.Date.t, float) => Js.Date.t = "default";
[@bs.module "date-fns/differenceInSeconds"]
external differenceInSeconds: (Js.Date.t, Js.Date.t) => int = "default";
[@bs.module "date-fns/differenceInSeconds"]
external differenceInSecondsf: (Js.Date.t, Js.Date.t) => float = "default";
[@bs.module "date-fns/endOfSecond"] external endOfSecond: Js.Date.t => Js.Date.t = "default";
[@bs.module "date-fns/getSeconds"] external getSeconds: Js.Date.t => int = "default";
[@bs.module "date-fns/getSeconds"] external getSecondsf: Js.Date.t => float = "default";
[@bs.module "date-fns/isSameSecond"] external isSameSecond: (Js.Date.t, Js.Date.t) => bool = "default";
[@bs.module "date-fns/isThisSecond"] external isThisSecond: Js.Date.t => bool = "default";
[@bs.module "date-fns/setSeconds"] external setSeconds: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/setSeconds"] external setSecondsf: (Js.Date.t, float) => Js.Date.t = "default";
[@bs.module "date-fns/startOfSecond"] external startOfSecond: Js.Date.t => Js.Date.t = "default";
[@bs.module "date-fns/subSeconds"] external subSeconds: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/subSeconds"] external subSecondsf: (Js.Date.t, float) => Js.Date.t = "default";

// Minute Helpers
[@bs.module "date-fns/addMinutes"] external addMinutes: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/addMinutes"] external addMinutesf: (Js.Date.t, float) => Js.Date.t = "default";
[@bs.module "date-fns/differenceInMinutes"]
external differenceInMinutes: (Js.Date.t, Js.Date.t) => int = "default";
[@bs.module "date-fns/differenceInMinutes"]
external differenceInMinutesf: (Js.Date.t, Js.Date.t) => float = "default";
[@bs.module "date-fns/endOfMinute"] external endOfMinute: Js.Date.t => Js.Date.t = "default";
[@bs.module "date-fns/getMinutes"] external getMinutes: Js.Date.t => int = "default";
[@bs.module "date-fns/getMinutes"] external getMinutesf: Js.Date.t => float = "default";
[@bs.module "date-fns/isSameMinute"] external isSameMinute: (Js.Date.t, Js.Date.t) => bool = "default";
[@bs.module "date-fns/isThisMinute"] external isThisMinute: Js.Date.t => bool = "default";
[@bs.module "date-fns/roundToNearestMinutes"]
external roundToNearestMinutes: Js.Date.t => Js.Date.t = "default";
type roundToNearestMinutesOptions = {nearestTo: option(int)};
[@bs.module "date-fns/roundToNearestMinutes"]
external roundToNearestMinutesOpt: (Js.Date.t, roundToNearestMinutesOptions) => Js.Date.t =
  "default";
[@bs.module "date-fns/setMinutes"] external setMinutes: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/startOfMinute"] external startOfMinute: Js.Date.t => Js.Date.t = "default";
[@bs.module "date-fns/subMinutes"] external subMinutes: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/subMinutes"] external subMinutesf: (Js.Date.t, float) => Js.Date.t = "default";

// Hour Helpers
[@bs.module "date-fns/addHours"] external addHours: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/addHours"] external addHoursf: (Js.Date.t, float) => Js.Date.t = "default";
[@bs.module "date-fns/differenceInHours"]
external differenceInHours: (Js.Date.t, Js.Date.t) => int = "default";
[@bs.module "date-fns/differenceInHours"]
external differenceInHoursf: (Js.Date.t, Js.Date.t) => float = "default";
[@bs.module "date-fns/endOfHour"] external endOfHour: Js.Date.t => Js.Date.t = "default";
[@bs.module "date-fns/getHours"] external getHours: Js.Date.t => int = "default";
[@bs.module "date-fns/getHours"] external getHoursf: Js.Date.t => float = "default";
[@bs.module "date-fns/isSameHour"] external isSameHour: (Js.Date.t, Js.Date.t) => bool = "default";
[@bs.module "date-fns/isThisHour"] external isThisHour: Js.Date.t => bool = "default";
[@bs.module "date-fns/setHours"] external setHours: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/setHours"] external setHoursf: (Js.Date.t, float) => Js.Date.t = "default";
[@bs.module "date-fns/startOfHour"] external startOfHour: Js.Date.t => Js.Date.t = "default";
[@bs.module "date-fns/subHours"] external subHours: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/subHours"] external subHoursf: (Js.Date.t, float) => Js.Date.t = "default";

// Day Helpers
[@bs.module "date-fns/addBusinessDays"] external addBusinessDays: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/addBusinessDays"]
external addBusinessDaysf: (Js.Date.t, float) => Js.Date.t = "default";
[@bs.module "date-fns/addDays"] external addDays: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/addDays"] external addDaysf: (Js.Date.t, float) => Js.Date.t = "default";
[@bs.module "date-fns/differenceInBusinessDays"]
external differenceInBusinessDays: (Js.Date.t, Js.Date.t) => int =
  "default";
[@bs.module "date-fns/differenceInBusinessDays"]
external differenceInBusinessDaysf: (Js.Date.t, Js.Date.t) => float =
  "default";
[@bs.module "date-fns/differenceInCalendarDays"]
external differenceInCalendarDays: (Js.Date.t, Js.Date.t) => int =
  "default";
[@bs.module "date-fns/differenceInCalendarDays"]
external differenceInCalendarDaysf: (Js.Date.t, Js.Date.t) => float =
  "default";
[@bs.module "date-fns/differenceInDays"]
external differenceInDays: (Js.Date.t, Js.Date.t) => int = "default";
[@bs.module "date-fns/differenceInDays"]
external differenceInDaysf: (Js.Date.t, Js.Date.t) => float = "default";
[@bs.module "date-fns/endOfDay"] external endOfDay: Js.Date.t => Js.Date.t = "default";
[@bs.module "date-fns/endOfToday"] external endOfToday: unit => Js.Date.t = "default";
[@bs.module "date-fns/endOfTomorrow"] external endOfTomorrow: unit => Js.Date.t = "default";
[@bs.module "date-fns/endOfYesterday"] external endOfYesterday: unit => Js.Date.t = "default";
[@bs.module "date-fns/getDate"] external getDate: Js.Date.t => int = "default";
[@bs.module "date-fns/getDate"] external getDatef: Js.Date.t => float = "default";
[@bs.module "date-fns/getDayOfYear"] external getDayOfYear: Js.Date.t => int = "default";
[@bs.module "date-fns/getDayOfYear"] external getDayOfYearf: Js.Date.t => float = "default";
[@bs.module "date-fns/isSameDay"] external isSameDay: (Js.Date.t, Js.Date.t) => bool = "default";
[@bs.module "date-fns/isToday"] external isToday: Js.Date.t => bool = "default";
[@bs.module "date-fns/isTomorrow"] external isTomorrow: Js.Date.t => bool = "default";
[@bs.module "date-fns/isYesterday"] external isYesterday: Js.Date.t => bool = "default";
[@bs.module "date-fns/setDate"] external setDate: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/setDate"] external setDatef: (Js.Date.t, float) => Js.Date.t = "default";
[@bs.module "date-fns/setDayOfYear"] external setDayOfYear: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/setDayOfYear"] external setDayOfYearf: (Js.Date.t, float) => Js.Date.t = "default";
[@bs.module "date-fns/startOfDay"] external startOfDay: Js.Date.t => Js.Date.t = "default";
[@bs.module "date-fns/startOfToday"] external startOfToday: unit => Js.Date.t = "default";
[@bs.module "date-fns/startOfTomorrow"] external startOfTomorrow: unit => Js.Date.t = "default";
[@bs.module "date-fns/startOfYesterday"] external startOfYesterday: unit => Js.Date.t = "default";
[@bs.module "date-fns/subBusinessDays"] external subBusinessDays: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/subBusinessDays"]
external subBusinessDaysf: (Js.Date.t, float) => Js.Date.t = "default";
[@bs.module "date-fns/subDays"] external subDays: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/subDays"] external subDaysf: (Js.Date.t, float) => Js.Date.t = "default";

// Weekday Helpers
[@bs.module "date-fns/getDay"] external getDay: Js.Date.t => int = "default";
[@bs.module "date-fns/getDay"] external getDayf: Js.Date.t => float = "default";
[@bs.module "date-fns/getISODay"] external getISODay: Js.Date.t => int = "default";
[@bs.module "date-fns/getISODay"] external getISODayf: Js.Date.t => float = "default";
[@bs.module "date-fns/isFriday"] external isFriday: Js.Date.t => bool = "default";
[@bs.module "date-fns/isMonday"] external isMonday: Js.Date.t => bool = "default";
[@bs.module "date-fns/isSaturday"] external isSaturday: Js.Date.t => bool = "default";
[@bs.module "date-fns/isSunday"] external isSunday: Js.Date.t => bool = "default";
[@bs.module "date-fns/isThursday"] external isThursday: Js.Date.t => bool = "default";
[@bs.module "date-fns/isTuesday"] external isTuesday: Js.Date.t => bool = "default";
[@bs.module "date-fns/isWednesday"] external isWednesday: Js.Date.t => bool = "default";
[@bs.module "date-fns/isWeekend"] external isWeekend: Js.Date.t => bool = "default";
[@bs.module "date-fns/setDay"] external setDay: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/setDay"] external setDayf: (Js.Date.t, float) => Js.Date.t = "default";
type setDayOptions = {
  locale: option(locale),
  weekStartsOn: option(int),
};
[@bs.module "date-fns/setDay"] external setDayOpt: (Js.Date.t, int, setDayOptions) => Js.Date.t = "default";
[@bs.module "date-fns/setDay"]
external setDayOptf: (Js.Date.t, float, setDayOptions) => Js.Date.t = "default";
[@bs.module "date-fns/setISODay"] external setISODay: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/setISODay"] external setISODayf: (Js.Date.t, float) => Js.Date.t = "default";

// Week Helpers
type weekOptions = {
  locale: option(locale),
  weekStartsOn: option(int),
};
[@bs.module "date-fns/addWeeks"] external addWeeks: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/addWeeks"] external addWeeksf: (Js.Date.t, float) => Js.Date.t = "default";
[@bs.module "date-fns/differenceInCalendarWeeks"]
external differenceInCalendarWeeks: (Js.Date.t, Js.Date.t) => int =
  "default";
[@bs.module "date-fns/differenceInCalendarWeeks"]
external differenceInCalendarWeeksOpt: (Js.Date.t, Js.Date.t, weekOptions) => int =
  "default";
[@bs.module "date-fns/differenceInCalendarWeeks"]
external differenceInCalendarWeeksf: (Js.Date.t, Js.Date.t) => float =
  "default";
external differenceInCalendarWeeksOptf: (Js.Date.t, Js.Date.t, weekOptions) => float =
  "date-fns/differenceInCalendarWeeks";
[@bs.module "date-fns/differenceInWeeks"]
external differenceInWeeks: (Js.Date.t, Js.Date.t) => int = "default";
[@bs.module "date-fns/differenceInWeeks"]
external differenceInWeeksf: (Js.Date.t, Js.Date.t) => float = "default";
[@bs.module "date-fns/endOfWeek"] external endOfWeek: Js.Date.t => Js.Date.t = "default";
[@bs.module "date-fns/endOfWeek"] external endOfWeekOpt: (Js.Date.t, weekOptions) => Js.Date.t = "default";
[@bs.module "date-fns/getWeek"] external getWeek: Js.Date.t => int = "default";
[@bs.module "date-fns/getWeek"] external getWeekf: Js.Date.t => float = "default";
type getWeekOptions = {
  locale: option(locale),
  weekStartsOn: option(int),
  firstWeekContainsDate: option(int),
};
[@bs.module "date-fns/getWeek"] external getWeekOpt: (Js.Date.t, getWeekOptions) => int = "default";
[@bs.module "date-fns/getWeek"] external getWeekOptf: (Js.Date.t, getWeekOptions) => float = "default";
[@bs.module "date-fns/getWeekOfMonth"] external getWeekOfMonth: Js.Date.t => int = "default";
[@bs.module "date-fns/getWeekOfMonth"] external getWeekOfMonthf: Js.Date.t => float = "default";
external getWeekOfMonthOpt: (Js.Date.t, weekOptions) => int = "date-fns/getWeekOfMonth";
[@bs.module "date-fns/getWeekOfMonth"]
external getWeekOfMonthOptf: (Js.Date.t, weekOptions) => float = "default";
[@bs.module "date-fns/getWeeksInMonth"] external getWeeksInMonth: Js.Date.t => int = "default";
[@bs.module "date-fns/getWeeksInMonth"] external getWeeksInMonthf: Js.Date.t => float = "default";
external getWeeksInMonthOpt: (Js.Date.t, weekOptions) => int = "date-fns/getWeeksInMonth";
[@bs.module "date-fns/getWeeksInMonth"]
external getWeeksInMonthOptf: (Js.Date.t, weekOptions) => float = "default";
[@bs.module "date-fns/isSameWeek"] external isSameWeek: (Js.Date.t, Js.Date.t) => bool = "default";
[@bs.module "date-fns/isSameWeek"]
external isSameWeekOpt: (Js.Date.t, Js.Date.t, weekOptions) => bool = "default";
[@bs.module "date-fns/isThisWeek"] external isThisWeek: Js.Date.t => bool = "default";
[@bs.module "date-fns/isThisWeek"] external isThisWeekOpt: (Js.Date.t, weekOptions) => bool = "default";
[@bs.module "date-fns/lastDayOfWeek"] external lastDayOfWeek: Js.Date.t = "default";
[@bs.module "date-fns/lastDayOfWeek"] external lastDayOfWeekOpt: (Js.Date.t, weekOptions) = "default";
[@bs.module "date-fns/setWeek"] external setWeek: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/setWeek"] external setWeekf: (Js.Date.t, float) => Js.Date.t = "default";
type setWeekOptions = {
  locale: option(locale),
  weekStartsOn: option(int),
  firstWeekContainsDate: option(int),
};
[@bs.module "date-fns/setWeek"]
external setWeekOpt: (Js.Date.t, int, setWeekOptions) => Js.Date.t = "default";
[@bs.module "date-fns/setWeek"]
external setWeekOptf: (Js.Date.t, float, setWeekOptions) => Js.Date.t = "default";
[@bs.module "date-fns/startOfWeek"] external startOfWeek: Js.Date.t => Js.Date.t = "default";
[@bs.module "date-fns/startOfWeek"]
external startOfWeekOpt: (Js.Date.t, weekOptions) => Js.Date.t = "default";
[@bs.module "date-fns/subWeeks"] external subWeeks: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/subWeeks"] external subWeeksf: (Js.Date.t, float) => Js.Date.t = "default";

// ISO Week Helpers
[@bs.module "date-fns/differenceInCalendarISOWeeks"]
external differenceInCalendarISOWeeks: (Js.Date.t, Js.Date.t) => int =
  "default";
[@bs.module "date-fns/differenceInCalendarISOWeeks"]
external differenceInCalendarISOWeeksf: (Js.Date.t, Js.Date.t) => float =
  "default";
[@bs.module "date-fns/endOfISOWeek"] external endOfISOWeek: Js.Date.t => Js.Date.t = "default";
[@bs.module "date-fns/getISOWeek"] external getISOWeek: Js.Date.t => int = "default";
[@bs.module "date-fns/getISOWeek"] external getISOWeekf: Js.Date.t => float = "default";
[@bs.module "date-fns/isSameISOWeek"] external isSameISOWeek: (Js.Date.t, Js.Date.t) => bool = "default";
[@bs.module "date-fns/isThisISOWeek"] external isThisISOWeek: Js.Date.t => bool = "default";
[@bs.module "date-fns/lastDayOfISOWeek"] external lastDayOfISOWeek: Js.Date.t => Js.Date.t = "default";
[@bs.module "date-fns/setISOWeek"] external setISOWeek: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/setISOWeek"] external setISOWeekf: (Js.Date.t, float) => Js.Date.t = "default";
[@bs.module "date-fns/startOfISOWeek"] external startOfISOWeek: Js.Date.t => Js.Date.t = "default";

// Month Helpers
[@bs.module "date-fns/addMonths"] external addMonths: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/addMonths"] external addMonthsf: (Js.Date.t, float) => Js.Date.t = "default";
[@bs.module "date-fns/differenceInCalendarMonths"]
external differenceInCalendarMonths: (Js.Date.t, Js.Date.t) => int =
  "default";
[@bs.module "date-fns/differenceInCalendarMonths"]
external differenceInCalendarMonthsf: (Js.Date.t, Js.Date.t) => float =
  "default";
[@bs.module "date-fns/differenceInMonths"]
external differenceInMonths: (Js.Date.t, Js.Date.t) => int = "default";
[@bs.module "date-fns/differenceInMonths"]
external differenceInMonthsf: (Js.Date.t, Js.Date.t) => float = "default";
[@bs.module "date-fns/eachWeekendOfMonth"]
external eachWeekendOfMonth: Js.Date.t => array(Js.Date.t) = "default";
[@bs.module "date-fns/endOfMonth"] external endOfMonth: Js.Date.t => Js.Date.t = "default";
[@bs.module "date-fns/getDaysInMonth"] external getDaysInMonth: Js.Date.t => int = "default";
[@bs.module "date-fns/getDaysInMonth"] external getDaysInMonthf: Js.Date.t => float = "default";
[@bs.module "date-fns/getMonth"] external getMonth: Js.Date.t => int = "default";
[@bs.module "date-fns/getMonth"] external getMonthf: Js.Date.t => float = "default";
[@bs.module "date-fns/isFirstDayOfMonth"] external isFirstDayOfMonth: Js.Date.t => bool = "default";
[@bs.module "date-fns/isLastDayOfMonth"] external isLastDayOfMonth: Js.Date.t => bool = "default";
[@bs.module "date-fns/isSameMonth"] external isSameMonth: (Js.Date.t, Js.Date.t) => bool = "default";
[@bs.module "date-fns/isThisMonth"] external isThisMonth: Js.Date.t => bool = "default";
[@bs.module "date-fns/lastDayOfMonth"] external lastDayOfMonth: Js.Date.t => Js.Date.t = "default";
[@bs.module "date-fns/setMonth"] external setMonth: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/setMonth"] external setMonthf: (Js.Date.t, float) => Js.Date.t = "default";
[@bs.module "date-fns/startOfMonth"] external startOfMonth: Js.Date.t => Js.Date.t = "default";
[@bs.module "date-fns/subMonths"] external subMonths: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/subMonths"] external subMonthsf: (Js.Date.t, float) => Js.Date.t = "default";

// Quarter Helpers
[@bs.module "date-fns/addQuarters"] external addQuarters: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/addQuarters"] external addQuartersf: (Js.Date.t, float) => Js.Date.t = "default";
[@bs.module "date-fns/differenceInCalendarQuarters"]
external differenceInCalendarQuarters: (Js.Date.t, Js.Date.t) => int =
  "default";
[@bs.module "date-fns/differenceInCalendarQuarters"]
external differenceInCalendarQuartersf: (Js.Date.t, Js.Date.t) => float =
  "default";
[@bs.module "date-fns/differenceInQuarters"]
external differenceInQuarters: (Js.Date.t, Js.Date.t) => int = "default";
[@bs.module "date-fns/differenceInQuarters"]
external differenceInQuartersf: (Js.Date.t, Js.Date.t) => float = "default";
[@bs.module "date-fns/endOfQuarter"] external endOfQuarter: Js.Date.t => Js.Date.t = "default";
[@bs.module "date-fns/getQuarter"] external getQuarter: Js.Date.t => int = "default";
[@bs.module "date-fns/getQuarter"] external getQuarterf: Js.Date.t => float = "default";
[@bs.module "date-fns/isSameQuarter"] external isSameQuarter: (Js.Date.t, Js.Date.t) => bool = "default";
[@bs.module "date-fns/isThisQuarter"] external isThisQuarter: Js.Date.t => bool = "default";
[@bs.module "date-fns/lastDayOfQuarter"] external lastDayOfQuarter: Js.Date.t => Js.Date.t = "default";
type lastDayOfQuarterOptions = {additionalDigits: option(int)};
external lastDayOfQuarterOpt: (Js.Date.t, lastDayOfQuarterOptions) => Js.Date.t =
  "date-fns/lastDayOfQuarter";
[@bs.module "date-fns/setQuarter"] external setQuarter: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/setQuarter"] external setQuarterf: (Js.Date.t, float) => Js.Date.t = "default";
[@bs.module "date-fns/startOfQuarter"] external startOfQuarter: Js.Date.t => Js.Date.t = "default";
[@bs.module "date-fns/subQuarters"] external subQuarters: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/subQuarters"] external subQuartersf: (Js.Date.t, float) => Js.Date.t = "default";

// Year Helpers
[@bs.module "date-fns/addYears"] external addYears: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/addYears"] external addYearsf: (Js.Date.t, float) => Js.Date.t = "default";
[@bs.module "date-fns/differenceInCalendarYears"]
external differenceInCalendarYears: (Js.Date.t, Js.Date.t) => int =
  "default";
[@bs.module "date-fns/differenceInCalendarYears"]
external differenceInCalendarYearsf: (Js.Date.t, Js.Date.t) => float =
  "default";
[@bs.module "date-fns/differenceInYears"]
external differenceInYears: (Js.Date.t, Js.Date.t) => int = "default";
[@bs.module "date-fns/differenceInYears"]
external differenceInYearsf: (Js.Date.t, Js.Date.t) => float = "default";
[@bs.module "date-fns/eachWeekendOfYear"]
external eachWeekendOfYear: Js.Date.t => array(Js.Date.t) = "default";
[@bs.module "date-fns/endOfYear"] external endOfYear: Js.Date.t => Js.Date.t = "default";
[@bs.module "date-fns/getDaysInYear"] external getDaysInYear: Js.Date.t => int = "default";
[@bs.module "date-fns/getDaysInYear"] external getDaysInYearf: Js.Date.t => float = "default";
[@bs.module "date-fns/getYear"] external getYear: Js.Date.t => int = "default";
[@bs.module "date-fns/getYear"] external getYearf: Js.Date.t => float = "default";
[@bs.module "date-fns/isLeapYear"] external isLeapYear: Js.Date.t => bool = "default";
[@bs.module "date-fns/isSameYear"] external isSameYear: (Js.Date.t, Js.Date.t) => bool = "default";
[@bs.module "date-fns/isThisYear"] external isThisYear: Js.Date.t => bool = "default";
[@bs.module "date-fns/lastDayOfYear"] external lastDayOfYear: Js.Date.t => Js.Date.t = "default";
[@bs.module "date-fns/setYear"] external setYear: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/setYear"] external setYearf: (Js.Date.t, float) => Js.Date.t = "default";
[@bs.module "date-fns/startOfYear"] external startOfYear: Js.Date.t => Js.Date.t = "default";
[@bs.module "date-fns/subYears"] external subYears: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/subYears"] external subYearsf: (Js.Date.t, float) => Js.Date.t = "default";

// ISO Week-Numbering Year Helpers
[@bs.module "date-fns/addISOWeekYears"] external addISOWeekYears: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/addISOWeekYears"]
external addISOWeekYearsf: (Js.Date.t, float) => Js.Date.t = "default";
[@bs.module "date-fns/differenceInCalendarISOWeekYears"]
external differenceInCalendarISOWeekYears: (Js.Date.t, Js.Date.t) => int =
  "default";
external differenceInCalendarISOWeekYearsf: (Js.Date.t, Js.Date.t) => float =
  "date-fns/differenceInCalendarISOWeekYears";
[@bs.module "date-fns/differenceInISOWeekYears"]
external differenceInISOWeekYears: (Js.Date.t, Js.Date.t) => int =
  "default";
[@bs.module "date-fns/differenceInISOWeekYears"]
external differenceInISOWeekYearsf: (Js.Date.t, Js.Date.t) => float =
  "default";
[@bs.module "date-fns/endOfISOWeekYear"] external endOfISOWeekYear: Js.Date.t => Js.Date.t = "default";
[@bs.module "date-fns/getISOWeekYear"] external getISOWeekYear: Js.Date.t => int = "default";
[@bs.module "date-fns/getISOWeekYear"] external getISOWeekYearf: Js.Date.t => float = "default";
[@bs.module "date-fns/getISOWeeksInYear"] external getISOWeeksInYear: Js.Date.t => int = "default";
[@bs.module "date-fns/getISOWeeksInYear"] external getISOWeeksInYearf: Js.Date.t => float = "default";
[@bs.module "date-fns/isSameISOWeekYear"]
external isSameISOWeekYear: (Js.Date.t, Js.Date.t) => bool = "default";
[@bs.module "date-fns/lastDayOfISOWeekYear"]
external lastDayOfISOWeekYear: Js.Date.t => Js.Date.t = "default";
[@bs.module "date-fns/setISOWeekYear"] external setISOWeekYear: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/setISOWeekYear"] external setISOWeekYearf: (Js.Date.t, float) => Js.Date.t = "default";
[@bs.module "date-fns/startOfISOWeekYear"] external startOfISOWeekYear: Js.Date.t => Js.Date.t = "default";
[@bs.module "date-fns/subISOWeekYears"] external subISOWeekYears: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/subISOWeekYears"]
external subISOWeekYearsf: (Js.Date.t, float) => Js.Date.t = "default";

// Decade Helpers
[@bs.module "date-fns/endOfDecade"] external endOfDecade: Js.Date.t => Js.Date.t = "default";
type endOfDecadeOptions = {additionalDigits: option(int)};
[@bs.module "date-fns/endOfDecade"]
external endOfDecadeOpt: (Js.Date.t, endOfDecadeOptions) => Js.Date.t = "default";
[@bs.module "date-fns/getDecade"] external getDecade: Js.Date.t => int = "default";
[@bs.module "date-fns/getDecade"] external getDecadef: Js.Date.t => float = "default";
[@bs.module "date-fns/lastDayOfDecade"] external lastDayOfDecade: Js.Date.t => Js.Date.t = "default";
[@bs.module "date-fns/startOfDecade"] external startOfDecade: Js.Date.t => Js.Date.t = "default";

// Week-Numbering Year Helpers
type weekYearOptions = {
  locale: option(locale),
  weekStartsOn: option(int),
  firstWeekContainsDate: option(int),
};
[@bs.module "date-fns/getWeekYear"] external getWeekYear: Js.Date.t => int = "default";
[@bs.module "date-fns/getWeekYear"] external getWeekYearOpt: (Js.Date.t, weekYearOptions) => int = "default";
[@bs.module "date-fns/getWeekYear"] external getWeekYearf: Js.Date.t => float = "default";
[@bs.module "date-fns/getWeekYear"]
external getWeekYearOptf: (Js.Date.t, weekYearOptions) => float = "default";
[@bs.module "date-fns/setWeekYear"] external setWeekYear: (Js.Date.t, int) => Js.Date.t = "default";
[@bs.module "date-fns/setWeekYear"]
external setWeekYearOpt: (Js.Date.t, int, weekYearOptions) => Js.Date.t = "default";
[@bs.module "date-fns/setWeekYear"] external setWeekYearf: (Js.Date.t, float) => Js.Date.t = "default";
[@bs.module "date-fns/setWeekYear"]
external setWeekYearOptf: (Js.Date.t, float, weekYearOptions) => Js.Date.t =
  "default";
[@bs.module "date-fns/startOfWeekYear"] external startOfWeekYear: Js.Date.t => Js.Date.t = "default";
[@bs.module "date-fns/startOfWeekYear"]
external startOfWeekYearOpt: (Js.Date.t, weekYearOptions) => Js.Date.t =
  "default";
