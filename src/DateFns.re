type interval = {
  start: Js.Date.t,
  [@bs.as "end"]
  end_: Js.Date.t,
};

type locale;

// Common Helpers
[@bs.module]
external closestIndexTo: (Js.Date.t, array(Js.Date.t)) => int = "date-fns/closestIndexTo";
[@bs.module]
external closestTo: (Js.Date.t, array(Js.Date.t)) => Js.Date.t = "date-fns/closestTo";
[@bs.module] external compareAsc: (Js.Date.t, Js.Date.t) => int = "date-fns/compareAsc";
[@bs.module] external compareDesc: (Js.Date.t, Js.Date.t) => int = "date-fns/compareDesc";

[@bs.module] external format: (Js.Date.t, string) => string = "date-fns/format";
type formatOptions = {
  locale: option(locale),
  weekStartsOn: option(int),
  firstWeekContainsDate: option(int),
  useAdditionalWeekYearTokens: option(bool),
  useAdditionalDayOfYearTokens: option(bool),
};
[@bs.module] external formatOpt: (Js.Date.t, string, formatOptions) => string = "date-fns/format";
[@bs.module] external formatDistance: (Js.Date.t, Js.Date.t) => string = "date-fns/formatDistance";
type formatDistanceOptions = {
  includeSeconds: option(bool),
  addSuffix: option(bool),
  locale: option(locale),
};
[@bs.module]
external formatDistanceOpt: (Js.Date.t, Js.Date.t, formatDistanceOptions) => string =
  "date-fns/formatDistance";
[@bs.module]
external formatDistanceStrict: (Js.Date.t, Js.Date.t) => string = "date-fns/formatDistanceStrict";
type formatDistanceStrictOptions = {
  addSuffix: option(bool),
  unit: option(string),
  roundingMethod: option(string),
  locale: option(locale),
};
[@bs.module]
external formatDistanceStrictOpt: (Js.Date.t, Js.Date.t, formatDistanceStrictOptions) => string =
  "date-fns/formatDistanceStrict";
[@bs.module] external formatDistanceToNow: Js.Date.t => string = "date-fns/formatDistanceToNow";
type formatDistanceToNowOptions = {
  includeSeconds: option(bool),
  addSuffix: option(bool),
  locale: option(locale),
};
[@bs.module]
external formatDistanceToNowOpt: (Js.Date.t, formatDistanceToNowOptions) => string =
  "date-fns/formatDistanceToNow";
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

[@bs.module] external formatRFC3339: Js.Date.t => string = "date-fns/formatRFC3339";
type formatRFC3339Options = {fractionDigits: option(int)};
[@bs.module]
external formatRFC3339Options: (Js.Date.t, formatRFC3339Options) => string =
  "date-fns/formatRFC3339";
[@bs.module] external formatRFC7231: Js.Date.t => string = "date-fns/formatRFC7231";
[@bs.module] external formatRelative: (Js.Date.t, Js.Date.t) => string = "date-fns/formatRelative";
type formatRelativeOptions = {
  locale: option(locale),
  weekStartsOn: option(int),
};
[@bs.module]
external formatRelativeOpt: (Js.Date.t, Js.Date.t, formatRelativeOptions) => string =
  "date-fns/formatRelative";
[@bs.module] external isAfter: (Js.Date.t, Js.Date.t) => bool = "date-fns/isAfter";
[@bs.module] external isBefore: (Js.Date.t, Js.Date.t) => bool = "date-fns/isBefore";
[@bs.module] external isDate: 'a => bool = "date-fns/isDate";
[@bs.module] external isEqual: (Js.Date.t, Js.Date.t) => bool = "date-fns/isEqual";
[@bs.module] external isFuture: Js.Date.t => bool = "date-fns/isFuture";
[@bs.module] external isPast: Js.Date.t => bool = "date-fns/isPast";
[@bs.module] external isValid: 'a => bool = "date-fns/isValid";
[@bs.module] external lightFormat: (Js.Date.t, string) => string = "date-fns/lightFormat";
[@bs.module] external max: array(Js.Date.t) => Js.Date.t = "date-fns/max";
[@bs.module] external min: array(Js.Date.t) => Js.Date.t = "date-fns/min";
[@bs.module] external parse: (string, string, Js.Date.t) => Js.Date.t = "date-fns/parse";
type parseOptions = {
  locale: option(locale),
  weekStartsOn: option(int),
  firstWeekContainsDate: option(int),
  useAdditionalWeekYearTokens: option(bool),
  useAdditionalDayOfYearTokens: option(bool),
};
[@bs.module]
external parseOpt: (string, string, Js.Date.t, parseOptions) => Js.Date.t = "date-fns/parse";
[@bs.module] external parseISO: string => Js.Date.t = "date-fns/parseISO";
type parseISOOptions = {additionalDigits: option(int)};
[@bs.module] external parseISOOpt: (string, parseISOOptions) => Js.Date.t = "date-fns/parseISO";
[@bs.module] external parseJSONString: string => Js.Date.t = "date-fns/parseJSON";
[@bs.module] external parseJSONFloat: float => Js.Date.t = "date-fns/parseJSON";
[@bs.module] external parseJSONInt: int => Js.Date.t = "date-fns/parseJSON";
type setOptions = {
  year: option(int),
  month: option(int),
  date: option(int),
  hours: option(int),
  minutes: option(int),
  seconds: option(int),
  milliseconds: option(int),
};
[@bs.module] external set: (Js.Date.t, setOptions) => Js.Date.t = "date-fns/set";
[@bs.module] external toDateFloat: float => Js.Date.t = "date-fns/toDate";
[@bs.module] external toDateInt: int => Js.Date.t = "date-fns/toDate";

// Interval Helpers
[@bs.module]
external areIntervalsOverlapping: (Js.Date.t, Js.Date.t) => bool =
  "date-fns/areIntervalsOverlapping";
[@bs.module]
external eachDayOfInterval: interval => array(Js.Date.t) = "date-fns/eachDayOfInterval";
type eachDayOfIntervalOptions = {step: option(int)};
[@bs.module]
external eachDayOfIntervalOpt: (interval, eachDayOfIntervalOptions) => array(Js.Date.t) =
  "date-fns/eachDayOfInterval";
[@bs.module]
external eachWeekOfInterval: interval => array(Js.Date.t) = "date-fns/eachWeekOfInterval";
type eachWeekOfIntervalOptions = {
  locale: option(locale),
  weekStartsOn: option(int),
};
[@bs.module]
external eachWeekOfIntervalOpt: (interval, eachWeekOfIntervalOptions) => array(Js.Date.t) =
  "date-fns/eachWeekOfInterval";
[@bs.module]
external eachWeekendOfInterval: interval => array(Js.Date.t) = "date-fns/eachWeekendOfInterval";
[@bs.module]
external getOverlappingDaysInIntervals: (interval, interval) => int =
  "date-fns/getOverlappingDaysInIntervals";
[@bs.module]
external getOverlappingDaysInIntervalsf: (interval, interval) => float =
  "date-fns/getOverlappingDaysInIntervals";
[@bs.module]
external isWithinInterval: (Js.Date.t, interval) => bool = "date-fns/isWithinInterval";

// Timestamp Helpers
[@bs.module] external fromUnixTime: float => Js.Date.t = "date-fns/fromUnixTime";
[@bs.module] external getTime: Js.Date.t => float = "date-fns/getTime";
[@bs.module] external getUnixTime: Js.Date.t => float = "date-fns/getUnixTime";

// Millisecond Helpers
[@bs.module] external addMilliseconds: (Js.Date.t, int) => Js.Date.t = "date-fns/addMilliseconds";
[@bs.module]
external addMillisecondsf: (Js.Date.t, float) => Js.Date.t = "date-fns/addMilliseconds";
[@bs.module]
external differenceInMilliseconds: (Js.Date.t, Js.Date.t) => int =
  "date-fns/differenceInMilliseconds";
[@bs.module]
external differenceInMillisecondsf: (Js.Date.t, Js.Date.t) => float =
  "date-fns/differenceInMilliseconds";
[@bs.module] external getMilliseconds: Js.Date.t => int = "date-fns/getMilliseconds";
[@bs.module] external getMillisecondsf: Js.Date.t => float = "date-fns/getMilliseconds";
[@bs.module] external setMilliseconds: (Js.Date.t, int) => Js.Date.t = "date-fns/setMilliseconds";
[@bs.module]
external setMillisecondsf: (Js.Date.t, float) => Js.Date.t = "date-fns/setMilliseconds";
[@bs.module] external subMilliseconds: (Js.Date.t, int) => Js.Date.t = "date-fns/subMilliseconds";
[@bs.module]
external subMillisecondsf: (Js.Date.t, float) => Js.Date.t = "date-fns/subMilliseconds";

// Second Helpers
[@bs.module] external addSeconds: (Js.Date.t, int) => Js.Date.t = "date-fns/addSeconds";
[@bs.module] external addSecondsf: (Js.Date.t, float) => Js.Date.t = "date-fns/addSeconds";
[@bs.module]
external differenceInSeconds: (Js.Date.t, Js.Date.t) => int = "date-fns/differenceInSeconds";
[@bs.module]
external differenceInSecondsf: (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInSeconds";
[@bs.module] external endOfSecond: Js.Date.t => Js.Date.t = "date-fns/endOfSecond";
[@bs.module] external getSeconds: Js.Date.t => int = "date-fns/getSeconds";
[@bs.module] external getSecondsf: Js.Date.t => float = "date-fns/getSeconds";
[@bs.module] external isSameSecond: (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameSecond";
[@bs.module] external isThisSecond: Js.Date.t => bool = "date-fns/isThisSecond";
[@bs.module] external setSeconds: (Js.Date.t, int) => Js.Date.t = "date-fns/setSeconds";
[@bs.module] external setSecondsf: (Js.Date.t, float) => Js.Date.t = "date-fns/setSeconds";
[@bs.module] external startOfSecond: Js.Date.t => Js.Date.t = "date-fns/startOfSecond";
[@bs.module] external subSeconds: (Js.Date.t, int) => Js.Date.t = "date-fns/subSeconds";
[@bs.module] external subSecondsf: (Js.Date.t, float) => Js.Date.t = "date-fns/subSeconds";

// Minute Helpers
[@bs.module] external addMinutes: (Js.Date.t, int) => Js.Date.t = "date-fns/addMinutes";
[@bs.module] external addMinutesf: (Js.Date.t, float) => Js.Date.t = "date-fns/addMinutes";
[@bs.module]
external differenceInMinutes: (Js.Date.t, Js.Date.t) => int = "date-fns/differenceInMinutes";
[@bs.module]
external differenceInMinutesf: (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInMinutes";
[@bs.module] external endOfMinute: Js.Date.t => Js.Date.t = "date-fns/endOfMinute";
[@bs.module] external getMinutes: Js.Date.t => int = "date-fns/getMinutes";
[@bs.module] external getMinutesf: Js.Date.t => float = "date-fns/getMinutes";
[@bs.module] external isSameMinute: (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameMinute";
[@bs.module] external isThisMinute: Js.Date.t => bool = "date-fns/isThisMinute";
[@bs.module]
external roundToNearestMinutes: Js.Date.t => Js.Date.t = "date-fns/roundToNearestMinutes";
type roundToNearestMinutesOptions = {nearestTo: option(int)};
[@bs.module]
external roundToNearestMinutesOpt: (Js.Date.t, roundToNearestMinutesOptions) => Js.Date.t =
  "date-fns/roundToNearestMinutes";
[@bs.module] external setMinutes: (Js.Date.t, int) => Js.Date.t = "date-fns/setMinutes";
[@bs.module] external startOfMinute: Js.Date.t => Js.Date.t = "date-fns/startOfMinute";
[@bs.module] external subMinutes: (Js.Date.t, int) => Js.Date.t = "date-fns/subMinutes";
[@bs.module] external subMinutesf: (Js.Date.t, float) => Js.Date.t = "date-fns/subMinutes";

// Hour Helpers
[@bs.module] external addHours: (Js.Date.t, int) => Js.Date.t = "date-fns/addHours";
[@bs.module] external addHoursf: (Js.Date.t, float) => Js.Date.t = "date-fns/addHours";
[@bs.module]
external differenceInHours: (Js.Date.t, Js.Date.t) => int = "date-fns/differenceInHours";
[@bs.module]
external differenceInHoursf: (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInHours";
[@bs.module] external endOfHour: Js.Date.t => Js.Date.t = "date-fns/endOfHour";
[@bs.module] external getHours: Js.Date.t => int = "date-fns/getHours";
[@bs.module] external getHoursf: Js.Date.t => float = "date-fns/getHours";
[@bs.module] external isSameHour: (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameHour";
[@bs.module] external isThisHour: Js.Date.t => bool = "date-fns/isThisHour";
[@bs.module] external setHours: (Js.Date.t, int) => Js.Date.t = "date-fns/setHours";
[@bs.module] external setHoursf: (Js.Date.t, float) => Js.Date.t = "date-fns/setHours";
[@bs.module] external startOfHour: Js.Date.t => Js.Date.t = "date-fns/startOfHour";
[@bs.module] external subHours: (Js.Date.t, int) => Js.Date.t = "date-fns/subHours";
[@bs.module] external subHoursf: (Js.Date.t, float) => Js.Date.t = "date-fns/subHours";

// Day Helpers
[@bs.module] external addBusinessDays: (Js.Date.t, int) => Js.Date.t = "date-fns/addBusinessDays";
[@bs.module]
external addBusinessDaysf: (Js.Date.t, float) => Js.Date.t = "date-fns/addBusinessDays";
[@bs.module] external addDays: (Js.Date.t, int) => Js.Date.t = "date-fns/addDays";
[@bs.module] external addDaysf: (Js.Date.t, float) => Js.Date.t = "date-fns/addDays";
[@bs.module]
external differenceInBusinessDays: (Js.Date.t, Js.Date.t) => int =
  "date-fns/differenceInBusinessDays";
[@bs.module]
external differenceInBusinessDaysf: (Js.Date.t, Js.Date.t) => float =
  "date-fns/differenceInBusinessDays";
[@bs.module]
external differenceInCalendarDays: (Js.Date.t, Js.Date.t) => int =
  "date-fns/differenceInCalendarDays";
[@bs.module]
external differenceInCalendarDaysf: (Js.Date.t, Js.Date.t) => float =
  "date-fns/differenceInCalendarDays";
[@bs.module]
external differenceInDays: (Js.Date.t, Js.Date.t) => int = "date-fns/differenceInDays";
[@bs.module]
external differenceInDaysf: (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInDays";
[@bs.module] external endOfDay: Js.Date.t => Js.Date.t = "date-fns/endOfDay";
[@bs.module] external endOfToday: unit => Js.Date.t = "date-fns/endOfToday";
[@bs.module] external endOfTomorrow: unit => Js.Date.t = "date-fns/endOfTomorrow";
[@bs.module] external endOfYesterday: unit => Js.Date.t = "date-fns/endOfYesterday";
[@bs.module] external getDate: Js.Date.t => int = "date-fns/getDate";
[@bs.module] external getDatef: Js.Date.t => float = "date-fns/getDate";
[@bs.module] external getDayOfYear: Js.Date.t => int = "date-fns/getDayOfYear";
[@bs.module] external getDayOfYearf: Js.Date.t => float = "date-fns/getDayOfYear";
[@bs.module] external isSameDay: (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameDay";
[@bs.module] external isToday: Js.Date.t => bool = "date-fns/isToday";
[@bs.module] external isTomorrow: Js.Date.t => bool = "date-fns/isTomorrow";
[@bs.module] external isYesterday: Js.Date.t => bool = "date-fns/isYesterday";
[@bs.module] external setDate: (Js.Date.t, int) => Js.Date.t = "date-fns/setDate";
[@bs.module] external setDatef: (Js.Date.t, float) => Js.Date.t = "date-fns/setDate";
[@bs.module] external setDayOfYear: (Js.Date.t, int) => Js.Date.t = "date-fns/setDayOfYear";
[@bs.module] external setDayOfYearf: (Js.Date.t, float) => Js.Date.t = "date-fns/setDayOfYear";
[@bs.module] external startOfDay: Js.Date.t => Js.Date.t = "date-fns/startOfDay";
[@bs.module] external startOfToday: unit => Js.Date.t = "date-fns/startOfToday";
[@bs.module] external startOfTomorrow: unit => Js.Date.t = "date-fns/startOfTomorrow";
[@bs.module] external startOfYesterday: unit => Js.Date.t = "date-fns/startOfYesterday";
[@bs.module] external subBusinessDays: (Js.Date.t, int) => Js.Date.t = "date-fns/subBusinessDays";
[@bs.module]
external subBusinessDaysf: (Js.Date.t, float) => Js.Date.t = "date-fns/subBusinessDays";
[@bs.module] external subDays: (Js.Date.t, int) => Js.Date.t = "date-fns/subDays";
[@bs.module] external subDaysf: (Js.Date.t, float) => Js.Date.t = "date-fns/subDays";

// Weekday Helpers
[@bs.module] external getDay: Js.Date.t => int = "date-fns/getDay";
[@bs.module] external getDayf: Js.Date.t => float = "date-fns/getDay";
[@bs.module] external getISODay: Js.Date.t => int = "date-fns/getISODay";
[@bs.module] external getISODayf: Js.Date.t => float = "date-fns/getISODay";
[@bs.module] external isFriday: Js.Date.t => bool = "date-fns/isFriday";
[@bs.module] external isMonday: Js.Date.t => bool = "date-fns/isMonday";
[@bs.module] external isSaturday: Js.Date.t => bool = "date-fns/isSaturday";
[@bs.module] external isSunday: Js.Date.t => bool = "date-fns/isSunday";
[@bs.module] external isThursday: Js.Date.t => bool = "date-fns/isThursday";
[@bs.module] external isTuesday: Js.Date.t => bool = "date-fns/isTuesday";
[@bs.module] external isWednesday: Js.Date.t => bool = "date-fns/isWednesday";
[@bs.module] external isWeekend: Js.Date.t => bool = "date-fns/isWeekend";
[@bs.module] external setDay: (Js.Date.t, int) => Js.Date.t = "date-fns/setDay";
[@bs.module] external setDayf: (Js.Date.t, float) => Js.Date.t = "date-fns/setDay";
type setDayOptions = {
  locale: option(locale),
  weekStartsOn: option(int),
};
[@bs.module] external setDayOpt: (Js.Date.t, int, setDayOptions) => Js.Date.t = "date-fns/setDay";
[@bs.module]
external setDayOptf: (Js.Date.t, float, setDayOptions) => Js.Date.t = "date-fns/setDay";
[@bs.module] external setISODay: (Js.Date.t, int) => Js.Date.t = "date-fns/setISODay";
[@bs.module] external setISODayf: (Js.Date.t, float) => Js.Date.t = "date-fns/setISODay";

// Week Helpers
type weekOptions = {
  locale: option(locale),
  weekStartsOn: option(int),
};
[@bs.module] external addWeeks: (Js.Date.t, int) => Js.Date.t = "date-fns/addWeeks";
[@bs.module] external addWeeksf: (Js.Date.t, float) => Js.Date.t = "date-fns/addWeeks";
[@bs.module]
external differenceInCalendarWeeks: (Js.Date.t, Js.Date.t) => int =
  "date-fns/differenceInCalendarWeeks";
[@bs.module]
external differenceInCalendarWeeksOpt: (Js.Date.t, Js.Date.t, weekOptions) => int =
  "date-fns/differenceInCalendarWeeks";
[@bs.module]
external differenceInCalendarWeeksf: (Js.Date.t, Js.Date.t) => float =
  "date-fns/differenceInCalendarWeeks";
external differenceInCalendarWeeksOptf: (Js.Date.t, Js.Date.t, weekOptions) => float =
  "date-fns/differenceInCalendarWeeks";
[@bs.module]
external differenceInWeeks: (Js.Date.t, Js.Date.t) => int = "date-fns/differenceInWeeks";
[@bs.module]
external differenceInWeeksf: (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInWeeks";
[@bs.module] external endOfWeek: Js.Date.t => Js.Date.t = "date-fns/endOfWeek";
[@bs.module] external endOfWeekOpt: (Js.Date.t, weekOptions) => Js.Date.t = "date-fns/endOfWeek";
[@bs.module] external getWeek: Js.Date.t => int = "date-fns/getWeek";
[@bs.module] external getWeekf: Js.Date.t => float = "date-fns/getWeek";
type getWeekOptions = {
  locale: option(locale),
  weekStartsOn: option(int),
  firstWeekContainsDate: option(int),
};
[@bs.module] external getWeekOpt: (Js.Date.t, getWeekOptions) => int = "date-fns/getWeek";
[@bs.module] external getWeekOptf: (Js.Date.t, getWeekOptions) => float = "date-fns/getWeek";
[@bs.module] external getWeekOfMonth: Js.Date.t => int = "date-fns/getWeekOfMonth";
[@bs.module] external getWeekOfMonthf: Js.Date.t => float = "date-fns/getWeekOfMonth";
external getWeekOfMonthOpt: (Js.Date.t, weekOptions) => int = "date-fns/getWeekOfMonth";
[@bs.module]
external getWeekOfMonthOptf: (Js.Date.t, weekOptions) => float = "date-fns/getWeekOfMonth";
[@bs.module] external getWeeksInMonth: Js.Date.t => int = "date-fns/getWeeksInMonth";
[@bs.module] external getWeeksInMonthf: Js.Date.t => float = "date-fns/getWeeksInMonth";
external getWeeksInMonthOpt: (Js.Date.t, weekOptions) => int = "date-fns/getWeeksInMonth";
[@bs.module]
external getWeeksInMonthOptf: (Js.Date.t, weekOptions) => float = "date-fns/getWeeksInMonth";
[@bs.module] external isSameWeek: (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameWeek";
[@bs.module]
external isSameWeekOpt: (Js.Date.t, Js.Date.t, weekOptions) => bool = "date-fns/isSameWeek";
[@bs.module] external isThisWeek: Js.Date.t => bool = "date-fns/isThisWeek";
[@bs.module] external isThisWeekOpt: (Js.Date.t, weekOptions) => bool = "date-fns/isThisWeek";
[@bs.module] external lastDayOfWeek: Js.Date.t = "date-fns/lastDayOfWeek";
[@bs.module] external lastDayOfWeekOpt: (Js.Date.t, weekOptions) = "date-fns/lastDayOfWeek";
[@bs.module] external setWeek: (Js.Date.t, int) => Js.Date.t = "date-fns/setWeek";
[@bs.module] external setWeekf: (Js.Date.t, float) => Js.Date.t = "date-fns/setWeek";
type setWeekOptions = {
  locale: option(locale),
  weekStartsOn: option(int),
  firstWeekContainsDate: option(int),
};
[@bs.module]
external setWeekOpt: (Js.Date.t, int, setWeekOptions) => Js.Date.t = "date-fns/setWeek";
[@bs.module]
external setWeekOptf: (Js.Date.t, float, setWeekOptions) => Js.Date.t = "date-fns/setWeek";
[@bs.module] external startOfWeek: Js.Date.t => Js.Date.t = "date-fns/startOfWeek";
[@bs.module]
external startOfWeekOpt: (Js.Date.t, weekOptions) => Js.Date.t = "date-fns/startOfWeek";
[@bs.module] external subWeeks: (Js.Date.t, int) => Js.Date.t = "date-fns/subWeeks";
[@bs.module] external subWeeksf: (Js.Date.t, float) => Js.Date.t = "date-fns/subWeeks";

// ISO Week Helpers
[@bs.module]
external differenceInCalendarISOWeeks: (Js.Date.t, Js.Date.t) => int =
  "date-fns/differenceInCalendarISOWeeks";
[@bs.module]
external differenceInCalendarISOWeeksf: (Js.Date.t, Js.Date.t) => float =
  "date-fns/differenceInCalendarISOWeeks";
[@bs.module] external endOfISOWeek: Js.Date.t => Js.Date.t = "date-fns/endOfISOWeek";
[@bs.module] external getISOWeek: Js.Date.t => int = "date-fns/getISOWeek";
[@bs.module] external getISOWeekf: Js.Date.t => float = "date-fns/getISOWeek";
[@bs.module] external isSameISOWeek: (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameISOWeek";
[@bs.module] external isThisISOWeek: Js.Date.t => bool = "date-fns/isThisISOWeek";
[@bs.module] external lastDayOfISOWeek: Js.Date.t => Js.Date.t = "date-fns/lastDayOfISOWeek";
[@bs.module] external setISOWeek: (Js.Date.t, int) => Js.Date.t = "date-fns/setISOWeek";
[@bs.module] external setISOWeekf: (Js.Date.t, float) => Js.Date.t = "date-fns/setISOWeek";
[@bs.module] external startOfISOWeek: Js.Date.t => Js.Date.t = "date-fns/startOfISOWeek";

// Month Helpers
[@bs.module] external addMonths: (Js.Date.t, int) => Js.Date.t = "date-fns/addMonths";
[@bs.module] external addMonthsf: (Js.Date.t, float) => Js.Date.t = "date-fns/addMonths";
[@bs.module]
external differenceInCalendarMonths: (Js.Date.t, Js.Date.t) => int =
  "date-fns/differenceInCalendarMonths";
[@bs.module]
external differenceInCalendarMonthsf: (Js.Date.t, Js.Date.t) => float =
  "date-fns/differenceInCalendarMonths";
[@bs.module]
external differenceInMonths: (Js.Date.t, Js.Date.t) => int = "date-fns/differenceInMonths";
[@bs.module]
external differenceInMonthsf: (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInMonths";
[@bs.module]
external eachWeekendOfMonth: Js.Date.t => array(Js.Date.t) = "date-fns/eachWeekendOfMonth";
[@bs.module] external endOfMonth: Js.Date.t => Js.Date.t = "date-fns/endOfMonth";
[@bs.module] external getDaysInMonth: Js.Date.t => int = "date-fns/getDaysInMonth";
[@bs.module] external getDaysInMonthf: Js.Date.t => float = "date-fns/getDaysInMonth";
[@bs.module] external getMonth: Js.Date.t => int = "date-fns/getMonth";
[@bs.module] external getMonthf: Js.Date.t => float = "date-fns/getMonth";
[@bs.module] external isFirstDayOfMonth: Js.Date.t => bool = "date-fns/isFirstDayOfMonth";
[@bs.module] external isLastDayOfMonth: Js.Date.t => bool = "date-fns/isLastDayOfMonth";
[@bs.module] external isSameMonth: (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameMonth";
[@bs.module] external isThisMonth: Js.Date.t => bool = "date-fns/isThisMonth";
[@bs.module] external lastDayOfMonth: Js.Date.t => Js.Date.t = "date-fns/lastDayOfMonth";
[@bs.module] external setMonth: (Js.Date.t, int) => Js.Date.t = "date-fns/setMonth";
[@bs.module] external setMonthf: (Js.Date.t, float) => Js.Date.t = "date-fns/setMonth";
[@bs.module] external startOfMonth: Js.Date.t => Js.Date.t = "date-fns/startOfMonth";
[@bs.module] external subMonths: (Js.Date.t, int) => Js.Date.t = "date-fns/subMonths";
[@bs.module] external subMonthsf: (Js.Date.t, float) => Js.Date.t = "date-fns/subMonths";

// Quarter Helpers
[@bs.module] external addQuarters: (Js.Date.t, int) => Js.Date.t = "date-fns/addQuarters";
[@bs.module] external addQuartersf: (Js.Date.t, float) => Js.Date.t = "date-fns/addQuarters";
[@bs.module]
external differenceInCalendarQuarters: (Js.Date.t, Js.Date.t) => int =
  "date-fns/differenceInCalendarQuarters";
[@bs.module]
external differenceInCalendarQuartersf: (Js.Date.t, Js.Date.t) => float =
  "date-fns/differenceInCalendarQuarters";
[@bs.module]
external differenceInQuarters: (Js.Date.t, Js.Date.t) => int = "date-fns/differenceInQuarters";
[@bs.module]
external differenceInQuartersf: (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInQuarters";
[@bs.module] external endOfQuarter: Js.Date.t => Js.Date.t = "date-fns/endOfQuarter";
[@bs.module] external getQuarter: Js.Date.t => int = "date-fns/getQuarter";
[@bs.module] external getQuarterf: Js.Date.t => float = "date-fns/getQuarter";
[@bs.module] external isSameQuarter: (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameQuarter";
[@bs.module] external isThisQuarter: Js.Date.t => bool = "date-fns/isThisQuarter";
[@bs.module] external lastDayOfQuarter: Js.Date.t => Js.Date.t = "date-fns/lastDayOfQuarter";
type lastDayOfQuarterOptions = {additionalDigits: option(int)};
external lastDayOfQuarterOpt: (Js.Date.t, lastDayOfQuarterOptions) => Js.Date.t =
  "date-fns/lastDayOfQuarter";
[@bs.module] external setQuarter: (Js.Date.t, int) => Js.Date.t = "date-fns/setQuarter";
[@bs.module] external setQuarterf: (Js.Date.t, float) => Js.Date.t = "date-fns/setQuarter";
[@bs.module] external startOfQuarter: Js.Date.t => Js.Date.t = "date-fns/startOfQuarter";
[@bs.module] external subQuarters: (Js.Date.t, int) => Js.Date.t = "date-fns/subQuarters";
[@bs.module] external subQuartersf: (Js.Date.t, float) => Js.Date.t = "date-fns/subQuarters";

// Year Helpers
[@bs.module] external addYears: (Js.Date.t, int) => Js.Date.t = "date-fns/addYears";
[@bs.module] external addYearsf: (Js.Date.t, float) => Js.Date.t = "date-fns/addYears";
[@bs.module]
external differenceInCalendarYears: (Js.Date.t, Js.Date.t) => int =
  "date-fns/differenceInCalendarYears";
[@bs.module]
external differenceInCalendarYearsf: (Js.Date.t, Js.Date.t) => float =
  "date-fns/differenceInCalendarYears";
[@bs.module]
external differenceInYears: (Js.Date.t, Js.Date.t) => int = "date-fns/differenceInYears";
[@bs.module]
external differenceInYearsf: (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInYears";
[@bs.module]
external eachWeekendOfYear: Js.Date.t => array(Js.Date.t) = "date-fns/eachWeekendOfYear";
[@bs.module] external endOfYear: Js.Date.t => Js.Date.t = "date-fns/endOfYear";
[@bs.module] external getDaysInYear: Js.Date.t => int = "date-fns/getDaysInYear";
[@bs.module] external getDaysInYearf: Js.Date.t => float = "date-fns/getDaysInYear";
[@bs.module] external getYear: Js.Date.t => int = "date-fns/getYear";
[@bs.module] external getYearf: Js.Date.t => float = "date-fns/getYear";
[@bs.module] external isLeapYear: Js.Date.t => bool = "date-fns/isLeapYear";
[@bs.module] external isSameYear: (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameYear";
[@bs.module] external isThisYear: Js.Date.t => bool = "date-fns/isThisYear";
[@bs.module] external lastDayOfYear: Js.Date.t => Js.Date.t = "date-fns/lastDayOfYear";
[@bs.module] external setYear: (Js.Date.t, int) => Js.Date.t = "date-fns/setYear";
[@bs.module] external setYearf: (Js.Date.t, float) => Js.Date.t = "date-fns/setYear";
[@bs.module] external startOfYear: Js.Date.t => Js.Date.t = "date-fns/startOfYear";
[@bs.module] external subYears: (Js.Date.t, int) => Js.Date.t = "date-fns/subYears";
[@bs.module] external subYearsf: (Js.Date.t, float) => Js.Date.t = "date-fns/subYears";

// ISO Week-Numbering Year Helpers
[@bs.module] external addISOWeekYears: (Js.Date.t, int) => Js.Date.t = "date-fns/addISOWeekYears";
[@bs.module]
external addISOWeekYearsf: (Js.Date.t, float) => Js.Date.t = "date-fns/addISOWeekYears";
[@bs.module]
external differenceInCalendarISOWeekYears: (Js.Date.t, Js.Date.t) => int =
  "date-fns/differenceInCalendarISOWeekYears";
external differenceInCalendarISOWeekYearsf: (Js.Date.t, Js.Date.t) => float =
  "date-fns/differenceInCalendarISOWeekYears";
[@bs.module]
external differenceInISOWeekYears: (Js.Date.t, Js.Date.t) => int =
  "date-fns/differenceInISOWeekYears";
[@bs.module]
external differenceInISOWeekYearsf: (Js.Date.t, Js.Date.t) => float =
  "date-fns/differenceInISOWeekYears";
[@bs.module] external endOfISOWeekYear: Js.Date.t => Js.Date.t = "date-fns/endOfISOWeekYear";
[@bs.module] external getISOWeekYear: Js.Date.t => int = "date-fns/getISOWeekYear";
[@bs.module] external getISOWeekYearf: Js.Date.t => float = "date-fns/getISOWeekYear";
[@bs.module] external getISOWeeksInYear: Js.Date.t => int = "date-fns/getISOWeeksInYear";
[@bs.module] external getISOWeeksInYearf: Js.Date.t => float = "date-fns/getISOWeeksInYear";
[@bs.module]
external isSameISOWeekYear: (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameISOWeekYear";
[@bs.module]
external lastDayOfISOWeekYear: Js.Date.t => Js.Date.t = "date-fns/lastDayOfISOWeekYear";
[@bs.module] external setISOWeekYear: (Js.Date.t, int) => Js.Date.t = "date-fns/setISOWeekYear";
[@bs.module] external setISOWeekYearf: (Js.Date.t, float) => Js.Date.t = "date-fns/setISOWeekYear";
[@bs.module] external startOfISOWeekYear: Js.Date.t => Js.Date.t = "date-fns/startOfISOWeekYear";
[@bs.module] external subISOWeekYears: (Js.Date.t, int) => Js.Date.t = "date-fns/subISOWeekYears";
[@bs.module]
external subISOWeekYearsf: (Js.Date.t, float) => Js.Date.t = "date-fns/subISOWeekYears";

// Decade Helpers
[@bs.module] external endOfDecade: Js.Date.t => Js.Date.t = "date-fns/endOfDecade";
type endOfDecadeOptions = {additionalDigits: option(int)};
[@bs.module]
external endOfDecadeOpt: (Js.Date.t, endOfDecadeOptions) => Js.Date.t = "date-fns/endOfDecade";
[@bs.module] external getDecade: Js.Date.t => int = "date-fns/getDecade";
[@bs.module] external getDecadef: Js.Date.t => float = "date-fns/getDecade";
[@bs.module] external lastDayOfDecade: Js.Date.t => Js.Date.t = "date-fns/lastDayOfDecade";
[@bs.module] external startOfDecade: Js.Date.t => Js.Date.t = "date-fns/startOfDecade";

// Week-Numbering Year Helpers
type weekYearOptions = {
  locale: option(locale),
  weekStartsOn: option(int),
  firstWeekContainsDate: option(int),
};
[@bs.module] external getWeekYear: Js.Date.t => int = "date-fns/getWeekYear";
[@bs.module] external getWeekYearOpt: (Js.Date.t, weekYearOptions) => int = "date-fns/getWeekYear";
[@bs.module] external getWeekYearf: Js.Date.t => float = "date-fns/getWeekYear";
[@bs.module]
external getWeekYearOptf: (Js.Date.t, weekYearOptions) => float = "date-fns/getWeekYear";
[@bs.module] external setWeekYear: (Js.Date.t, int) => Js.Date.t = "date-fns/setWeekYear";
[@bs.module]
external setWeekYearOpt: (Js.Date.t, int, weekYearOptions) => Js.Date.t = "date-fns/setWeekYear";
[@bs.module] external setWeekYearf: (Js.Date.t, float) => Js.Date.t = "date-fns/setWeekYear";
[@bs.module]
external setWeekYearOptf: (Js.Date.t, float, weekYearOptions) => Js.Date.t =
  "date-fns/setWeekYear";
[@bs.module] external startOfWeekYear: Js.Date.t => Js.Date.t = "date-fns/startOfWeekYear";
[@bs.module]
external startOfWeekYearOpt: (Js.Date.t, weekYearOptions) => Js.Date.t =
  "date-fns/startOfWeekYear";
