type interval = {
  start: Js.Date.t,
  @as("end")
  end_: Js.Date.t,
}

type locale

// Common Helpers
@module
external closestIndexTo: (Js.Date.t, array<Js.Date.t>) => int = "date-fns/closestIndexTo"
@module
external closestTo: (Js.Date.t, array<Js.Date.t>) => Js.Date.t = "date-fns/closestTo"
@module external compareAsc: (Js.Date.t, Js.Date.t) => int = "date-fns/compareAsc"

@module external compareDesc: (Js.Date.t, Js.Date.t) => int = "date-fns/compareDesc"

@module external format: (Js.Date.t, string) => string = "date-fns/format"
type formatOptions = {
  locale: option<locale>,
  weekStartsOn: option<int>,
  firstWeekContainsDate: option<int>,
  useAdditionalWeekYearTokens: option<bool>,
  useAdditionalDayOfYearTokens: option<bool>,
}
@module
external formatOpt: (Js.Date.t, string, formatOptions) => string = "date-fns/formatOpt"

@module
external formatDistance: (Js.Date.t, Js.Date.t) => string = "date-fns/formatDistance"
type formatDistanceOptions = {
  includeSeconds: option<bool>,
  addSuffix: option<bool>,
  locale: option<locale>,
}
@module
external formatDistanceOpt: (Js.Date.t, Js.Date.t, formatDistanceOptions) => string =
  "date-fns/formatDistance"
@module
external formatDistanceStrict: (Js.Date.t, Js.Date.t) => string = "date-fns/formatDistanceStrict"
type formatDistanceStrictOptions = {
  addSuffix: option<bool>,
  unit: option<string>,
  roundingMethod: option<string>,
  locale: option<locale>,
}
@module
external formatDistanceStrictOpt: (Js.Date.t, Js.Date.t, formatDistanceStrictOptions) => string =
  "date-fns/formatDistanceStrict"
@module
external formatDistanceToNow: Js.Date.t => string = "date-fns/formatDistanceToNow"
type formatDistanceToNowOptions = {
  includeSeconds: option<bool>,
  addSuffix: option<bool>,
  locale: option<locale>,
}
@module
external formatDistanceToNowOpt: (Js.Date.t, formatDistanceToNowOptions) => string =
  "date-fns/formatDistanceToNow"

@module
external formatISO: Js.Date.t => string = "date-fns/formatISO"
type formatISOOptions = {
  format: option<string>,
  representation: option<string>,
}

@module
external formatISOOpt: (Js.Date.t, formatISOOptions) => string = "date-fns/formatISO"

@module
external formatISO9075: Js.Date.t => string = "date-fns/formatISO9075"
type formatISO9075Options = {
  format: option<string>,
  representation: option<string>,
}

@module
external formatISO9075Opt: (Js.Date.t, formatISO9075Options) => string = "date-fns/formatISO9075"

@module external formatRFC3339: Js.Date.t => string = "date-fns/formatRFC3339"
type formatRFC3339Options = {fractionDigits: option<int>}

@module
external formatRFC3339Options: (Js.Date.t, formatRFC3339Options) => string =
  "date-fns/formatRFC3339"

@module external formatRFC7231: Js.Date.t => string = "date-fns/formatRFC7231"

@module
external formatRelative: (Js.Date.t, Js.Date.t) => string = "date-fns/formatRelative"
type formatRelativeOptions = {
  locale: option<locale>,
  weekStartsOn: option<int>,
}
@module
external formatRelativeOpt: (Js.Date.t, Js.Date.t, formatRelativeOptions) => string =
  "date-fns/formatRelative"

@module external isAfter: (Js.Date.t, Js.Date.t) => bool = "date-fns/isAfter"
@module external isBefore: (Js.Date.t, Js.Date.t) => bool = "date-fns/isBefore"
@module external isDate: 'a => bool = "date-fns/isDate"
@module external isEqual: (Js.Date.t, Js.Date.t) => bool = "date-fns/isEqual"
@module external isFuture: Js.Date.t => bool = "date-fns/isFuture"
@module external isPast: Js.Date.t => bool = "date-fns/isPast"
@module external isValid: 'a => bool = "date-fns/isValid"
@module external lightFormat: (Js.Date.t, string) => string = "date-fns/lightFormat"
@module external max: array<Js.Date.t> => Js.Date.t = "date-fns/max"
@module external min: array<Js.Date.t> => Js.Date.t = "date-fns/min"
@module external parse: (string, string, Js.Date.t) => Js.Date.t = "date-fns/parse"
type parseOptions = {
  locale: option<locale>,
  weekStartsOn: option<int>,
  firstWeekContainsDate: option<int>,
  useAdditionalWeekYearTokens: option<bool>,
  useAdditionalDayOfYearTokens: option<bool>,
}
@module
external parseOpt: (string, string, Js.Date.t, parseOptions) => Js.Date.t = "date-fns/parse"
@module external parseISO: string => Js.Date.t = "date-fns/parseISO"
type parseISOOptions = {additionalDigits: option<int>}
@module
external parseISOOpt: (string, parseISOOptions) => Js.Date.t = "date-fns/parseISO"
@module external parseJSONString: string => Js.Date.t = "date-fns/parseJSON"
@module external parseJSONFloat: float => Js.Date.t = "date-fns/parseJSON"
@module external parseJSONInt: int => Js.Date.t = "date-fns/parseJSON"
type setOptions = {
  year: option<int>,
  month: option<int>,
  date: option<int>,
  hours: option<int>,
  minutes: option<int>,
  seconds: option<int>,
  milliseconds: option<int>,
}
@module external set: (Js.Date.t, setOptions) => Js.Date.t = "date-fns/set"
@module external toDateFloat: float => Js.Date.t = "date-fns/toDate"
@module external toDateInt: int => Js.Date.t = "date-fns/toDate"

// Interval Helpers

@module
external areIntervalsOverlapping: (interval, interval) => bool = "date-fns/areIntervalsOverlapping"

@module external eachDayOfInterval: interval => array<Js.Date.t> = "date-fns/eachDayOfInterval"

type eachDayOfIntervalOptions = {step: option<int>}
@module
external eachDayOfIntervalOpt: (interval, eachDayOfIntervalOptions) => array<Js.Date.t> =
  "date-fns/eachDayOfInterval"

@module
external eachWeekOfInterval: interval => array<Js.Date.t> = "date-fns/eachWeekOfInterval"
type eachWeekOfIntervalOptions = {
  locale: option<locale>,
  weekStartsOn: option<int>,
}
@module
external eachWeekOfIntervalOpt: (interval, eachWeekOfIntervalOptions) => array<Js.Date.t> =
  "date-fns/eachWeekOfInterval"

@module
external eachWeekendOfInterval: interval => array<Js.Date.t> = "date-fns/eachWeekendOfInterval"

@module
external getOverlappingDaysInIntervals: (interval, interval) => int =
  "date-fns/getOverlappingDaysInIntervals"
@module
external getOverlappingDaysInIntervalsf: (interval, interval) => float =
  "date-fns/getOverlappingDaysInIntervals"
@module
external isWithinInterval: (Js.Date.t, interval) => bool = "date-fns/isWithinInterval"

// Timestamp Helpers
@module external fromUnixTime: float => Js.Date.t = "date-fns/fromUnixTime"
@module external getTime: Js.Date.t => float = "date-fns/getTime"
@module external getUnixTime: Js.Date.t => float = "date-fns/getUnixTime"

// Millisecond Helpers
@module
external addMilliseconds: (Js.Date.t, int) => Js.Date.t = "date-fns/addMilliseconds"
@module
external addMillisecondsf: (Js.Date.t, float) => Js.Date.t = "date-fns/addMilliseconds"
@module
external differenceInMilliseconds: (Js.Date.t, Js.Date.t) => int =
  "date-fns/differenceInMilliseconds"
@module
external differenceInMillisecondsf: (Js.Date.t, Js.Date.t) => float =
  "date-fns/differenceInMilliseconds"
@module external getMilliseconds: Js.Date.t => int = "date-fns/getMilliseconds"
@module external getMillisecondsf: Js.Date.t => float = "date-fns/getMilliseconds"
@module
external setMilliseconds: (Js.Date.t, int) => Js.Date.t = "date-fns/setMilliseconds"
@module
external setMillisecondsf: (Js.Date.t, float) => Js.Date.t = "date-fns/setMilliseconds"
@module
external subMilliseconds: (Js.Date.t, int) => Js.Date.t = "date-fns/subMilliseconds"
@module
external subMillisecondsf: (Js.Date.t, float) => Js.Date.t = "date-fns/subMilliseconds"

// Second Helpers
@module external addSeconds: (Js.Date.t, int) => Js.Date.t = "date-fns/addSeconds"
@module external addSecondsf: (Js.Date.t, float) => Js.Date.t = "date-fns/addSeconds"
@module
external differenceInSeconds: (Js.Date.t, Js.Date.t) => int = "date-fns/differenceInSeconds"
@module
external differenceInSecondsf: (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInSeconds"
@module external endOfSecond: Js.Date.t => Js.Date.t = "date-fns/endOfSecond"
@module external getSeconds: Js.Date.t => int = "date-fns/getSeconds"
@module external getSecondsf: Js.Date.t => float = "date-fns/getSeconds"
@module external isSameSecond: (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameSecond"
@module external isThisSecond: Js.Date.t => bool = "date-fns/isThisSecond"
@module external setSeconds: (Js.Date.t, int) => Js.Date.t = "date-fns/setSeconds"
@module external setSecondsf: (Js.Date.t, float) => Js.Date.t = "date-fns/setSeconds"
@module external startOfSecond: Js.Date.t => Js.Date.t = "date-fns/startOfSecond"
@module external subSeconds: (Js.Date.t, int) => Js.Date.t = "date-fns/subSeconds"
@module external subSecondsf: (Js.Date.t, float) => Js.Date.t = "date-fns/subSeconds"

// Minute Helpers
@module external addMinutes: (Js.Date.t, int) => Js.Date.t = "date-fns/addMinutes"
@module external addMinutesf: (Js.Date.t, float) => Js.Date.t = "date-fns/addMinutes"
@module
external differenceInMinutes: (Js.Date.t, Js.Date.t) => int = "date-fns/differenceInMinutes"
@module
external differenceInMinutesf: (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInMinutes"
@module external endOfMinute: Js.Date.t => Js.Date.t = "date-fns/endOfMinute"
@module external getMinutes: Js.Date.t => int = "date-fns/getMinutes"
@module external getMinutesf: Js.Date.t => float = "date-fns/getMinutes"
@module external isSameMinute: (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameMinute"
@module external isThisMinute: Js.Date.t => bool = "date-fns/isThisMinute"

@module
external roundToNearestMinutes: Js.Date.t => Js.Date.t = "date-fns/roundToNearestMinutes"
type roundToNearestMinutesOptions = {nearestTo: option<int>}

@module
external roundToNearestMinutesOpt: (Js.Date.t, roundToNearestMinutesOptions) => Js.Date.t =
  "date-fns/roundToNearestMinutes"
@module external setMinutes: (Js.Date.t, int) => Js.Date.t = "date-fns/setMinutes"
@module external startOfMinute: Js.Date.t => Js.Date.t = "date-fns/startOfMinute"
@module external subMinutes: (Js.Date.t, int) => Js.Date.t = "date-fns/subMinutes"
@module external subMinutesf: (Js.Date.t, float) => Js.Date.t = "date-fns/subMinutes"

// Hour Helpers
@module external addHours: (Js.Date.t, int) => Js.Date.t = "date-fns/addHours"
@module external addHoursf: (Js.Date.t, float) => Js.Date.t = "date-fns/addHours"
@module
external differenceInHours: (Js.Date.t, Js.Date.t) => int = "date-fns/differenceInHours"
@module
external differenceInHoursf: (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInHours"
@module external endOfHour: Js.Date.t => Js.Date.t = "date-fns/endOfHour"
@module external getHours: Js.Date.t => int = "date-fns/getHours"
@module external getHoursf: Js.Date.t => float = "date-fns/getHours"
@module external isSameHour: (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameHour"
@module external isThisHour: Js.Date.t => bool = "date-fns/isThisHour"
@module external setHours: (Js.Date.t, int) => Js.Date.t = "date-fns/setHours"
@module external setHoursf: (Js.Date.t, float) => Js.Date.t = "date-fns/setHours"
@module external startOfHour: Js.Date.t => Js.Date.t = "date-fns/startOfHour"
@module external subHours: (Js.Date.t, int) => Js.Date.t = "date-fns/subHours"
@module external subHoursf: (Js.Date.t, float) => Js.Date.t = "date-fns/subHours"

// Day Helpers
@module
external addBusinessDays: (Js.Date.t, int) => Js.Date.t = "date-fns/addBusinessDays"
@module
external addBusinessDaysf: (Js.Date.t, float) => Js.Date.t = "date-fns/addBusinessDays"
@module external addDays: (Js.Date.t, int) => Js.Date.t = "date-fns/addDays"
@module external addDaysf: (Js.Date.t, float) => Js.Date.t = "date-fns/addDays"
@module
external differenceInBusinessDays: (Js.Date.t, Js.Date.t) => int =
  "date-fns/differenceInBusinessDays"
@module
external differenceInBusinessDaysf: (Js.Date.t, Js.Date.t) => float =
  "date-fns/differenceInBusinessDays"
@module
external differenceInCalendarDays: (Js.Date.t, Js.Date.t) => int =
  "date-fns/differenceInCalendarDays"
@module
external differenceInCalendarDaysf: (Js.Date.t, Js.Date.t) => float =
  "date-fns/differenceInCalendarDays"
@module
external differenceInDays: (Js.Date.t, Js.Date.t) => int = "date-fns/differenceInDays"
@module
external differenceInDaysf: (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInDays"
@module external endOfDay: Js.Date.t => Js.Date.t = "date-fns/endOfDay"
@module external endOfToday: unit => Js.Date.t = "date-fns/endOfToday"
@module external endOfTomorrow: unit => Js.Date.t = "date-fns/endOfTomorrow"
@module external endOfYesterday: unit => Js.Date.t = "date-fns/endOfYesterday"
@module external getDate: Js.Date.t => int = "date-fns/getDate"
@module external getDatef: Js.Date.t => float = "date-fns/getDate"
@module external getDayOfYear: Js.Date.t => int = "date-fns/getDayOfYear"
@module external getDayOfYearf: Js.Date.t => float = "date-fns/getDayOfYear"
@module external isSameDay: (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameDay"
@module external isToday: Js.Date.t => bool = "date-fns/isToday"
@module external isTomorrow: Js.Date.t => bool = "date-fns/isTomorrow"
@module external isYesterday: Js.Date.t => bool = "date-fns/isYesterday"
@module external setDate: (Js.Date.t, int) => Js.Date.t = "date-fns/setDate"
@module external setDatef: (Js.Date.t, float) => Js.Date.t = "date-fns/setDate"
@module external setDayOfYear: (Js.Date.t, int) => Js.Date.t = "date-fns/setDayOfYear"
@module external setDayOfYearf: (Js.Date.t, float) => Js.Date.t = "date-fns/setDayOfYear"
@module external startOfDay: Js.Date.t => Js.Date.t = "date-fns/startOfDay"
@module external startOfToday: unit => Js.Date.t = "date-fns/startOfToday"
@module external startOfTomorrow: unit => Js.Date.t = "date-fns/startOfTomorrow"
@module external startOfYesterday: unit => Js.Date.t = "date-fns/startOfYesterday"
@module
external subBusinessDays: (Js.Date.t, int) => Js.Date.t = "date-fns/subBusinessDays"
@module
external subBusinessDaysf: (Js.Date.t, float) => Js.Date.t = "date-fns/subBusinessDays"
@module external subDays: (Js.Date.t, int) => Js.Date.t = "date-fns/subDays"
@module external subDaysf: (Js.Date.t, float) => Js.Date.t = "date-fns/subDays"

// Weekday Helpers
@module external getDay: Js.Date.t => int = "date-fns/getDay"
@module external getDayf: Js.Date.t => float = "date-fns/getDay"
@module external getISODay: Js.Date.t => int = "date-fns/getISODay"
@module external getISODayf: Js.Date.t => float = "date-fns/getISODay"
@module external isFriday: Js.Date.t => bool = "date-fns/isFriday"
@module external isMonday: Js.Date.t => bool = "date-fns/isMonday"
@module external isSaturday: Js.Date.t => bool = "date-fns/isSaturday"
@module external isSunday: Js.Date.t => bool = "date-fns/isSunday"
@module external isThursday: Js.Date.t => bool = "date-fns/isThursday"
@module external isTuesday: Js.Date.t => bool = "date-fns/isTuesday"
@module external isWednesday: Js.Date.t => bool = "date-fns/isWednesday"
@module external isWeekend: Js.Date.t => bool = "date-fns/isWeekend"
@module external setDay: (Js.Date.t, int) => Js.Date.t = "date-fns/setDay"
@module external setDayf: (Js.Date.t, float) => Js.Date.t = "date-fns/setDay"
type setDayOptions = {
  locale: option<locale>,
  weekStartsOn: option<int>,
}
@module
external setDayOpt: (Js.Date.t, int, setDayOptions) => Js.Date.t = "date-fns/setDay"
@module
external setDayOptf: (Js.Date.t, float, setDayOptions) => Js.Date.t = "date-fns/setDay"
@module external setISODay: (Js.Date.t, int) => Js.Date.t = "date-fns/setISODay"
@module external setISODayf: (Js.Date.t, float) => Js.Date.t = "date-fns/setISODay"

// Week Helpers
type weekOptions = {
  locale: option<locale>,
  weekStartsOn: option<int>,
}
@module external addWeeks: (Js.Date.t, int) => Js.Date.t = "date-fns/addWeeks"
@module external addWeeksf: (Js.Date.t, float) => Js.Date.t = "date-fns/addWeeks"

@module
external differenceInCalendarWeeks: (Js.Date.t, Js.Date.t) => int =
  "date-fns/differenceInCalendarWeeks"

@module
external differenceInCalendarWeeksOpt: (Js.Date.t, Js.Date.t, weekOptions) => int =
  "date-fns/differenceInCalendarWeeks"

@module
external differenceInCalendarWeeksf: (Js.Date.t, Js.Date.t) => float =
  "date-fns/differenceInCalendarWeeks"

@module
external differenceInCalendarWeeksOptf: (Js.Date.t, Js.Date.t, weekOptions) => float =
  "date-fns/differenceInCalendarWeeks"

@module
external differenceInWeeks: (Js.Date.t, Js.Date.t) => int = "date-fns/differenceInWeeks"
@module
external differenceInWeeksf: (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInWeeks"
@module external endOfWeek: Js.Date.t => Js.Date.t = "date-fns/endOfWeek"
@module
external endOfWeekOpt: (Js.Date.t, weekOptions) => Js.Date.t = "date-fns/endOfWeek"

@module external getWeek: Js.Date.t => int = "date-fns/getWeek"
@module external getWeekf: Js.Date.t => float = "date-fns/getWeek"
type getWeekOptions = {
  locale: option<locale>,
  weekStartsOn: option<int>,
  firstWeekContainsDate: option<int>,
}
@module external getWeekOpt: (Js.Date.t, getWeekOptions) => int = "date-fns/getWeek"
@module external getWeekOptf: (Js.Date.t, getWeekOptions) => float = "date-fns/getWeek"
@module external getWeekOfMonth: Js.Date.t => int = "date-fns/getWeekOfMonth"

@module external getWeekOfMonthf: Js.Date.t => float = "date-fns/getWeekOfMonth"
external getWeekOfMonthOpt: (Js.Date.t, weekOptions) => int = "date-fns/getWeekOfMonth"

@module
external getWeekOfMonthOptf: (Js.Date.t, weekOptions) => float = "date-fns/getWeekOfMonth"
@module external getWeeksInMonth: Js.Date.t => int = "date-fns/getWeeksInMonth"
@module external getWeeksInMonthf: Js.Date.t => float = "date-fns/getWeeksInMonth"
external getWeeksInMonthOpt: (Js.Date.t, weekOptions) => int = "date-fns/getWeeksInMonth"
@module
external getWeeksInMonthOptf: (Js.Date.t, weekOptions) => float = "date-fns/getWeeksInMonth"

@module external isSameWeek: (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameWeek"
@module
external isSameWeekOpt: (Js.Date.t, Js.Date.t, weekOptions) => bool = "date-fns/isSameWeek"
@module external isThisWeek: Js.Date.t => bool = "date-fns/isThisWeek"
@module external isThisWeekOpt: (Js.Date.t, weekOptions) => bool = "date-fns/isThisWeek"
@module external lastDayOfWeek: Js.Date.t = "date-fns/lastDayOfWeek"
@module external lastDayOfWeekOpt: (Js.Date.t, weekOptions) = "date-fns/lastDayOfWeek"
@module external setWeek: (Js.Date.t, int) => Js.Date.t = "date-fns/setWeek"
@module external setWeekf: (Js.Date.t, float) => Js.Date.t = "date-fns/setWeek"
type setWeekOptions = {
  locale: option<locale>,
  weekStartsOn: option<int>,
  firstWeekContainsDate: option<int>,
}
@module
external setWeekOpt: (Js.Date.t, int, setWeekOptions) => Js.Date.t = "date-fns/setWeek"
@module
external setWeekOptf: (Js.Date.t, float, setWeekOptions) => Js.Date.t = "date-fns/setWeek"
@module external startOfWeek: Js.Date.t => Js.Date.t = "date-fns/startOfWeek"
@module
external startOfWeekOpt: (Js.Date.t, weekOptions) => Js.Date.t = "date-fns/startOfWeek"
@module external subWeeks: (Js.Date.t, int) => Js.Date.t = "date-fns/subWeeks"
@module external subWeeksf: (Js.Date.t, float) => Js.Date.t = "date-fns/subWeeks"

// ISO Week Helpers
@module
external differenceInCalendarISOWeeks: (Js.Date.t, Js.Date.t) => int =
  "date-fns/differenceInCalendarISOWeeks"
@module
external differenceInCalendarISOWeeksf: (Js.Date.t, Js.Date.t) => float =
  "date-fns/differenceInCalendarISOWeeks"
@module external endOfISOWeek: Js.Date.t => Js.Date.t = "date-fns/endOfISOWeek"
@module external getISOWeek: Js.Date.t => int = "date-fns/getISOWeek"
@module external getISOWeekf: Js.Date.t => float = "date-fns/getISOWeek"
@module external isSameISOWeek: (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameISOWeek"
@module external isThisISOWeek: Js.Date.t => bool = "date-fns/isThisISOWeek"
@module external lastDayOfISOWeek: Js.Date.t => Js.Date.t = "date-fns/lastDayOfISOWeek"
@module external setISOWeek: (Js.Date.t, int) => Js.Date.t = "date-fns/setISOWeek"
@module external setISOWeekf: (Js.Date.t, float) => Js.Date.t = "date-fns/setISOWeek"
@module external startOfISOWeek: Js.Date.t => Js.Date.t = "date-fns/startOfISOWeek"

// Month Helpers
@module external addMonths: (Js.Date.t, int) => Js.Date.t = "date-fns/addMonths"
@module external addMonthsf: (Js.Date.t, float) => Js.Date.t = "date-fns/addMonths"
@module
external differenceInCalendarMonths: (Js.Date.t, Js.Date.t) => int =
  "date-fns/differenceInCalendarMonths"
@module
external differenceInCalendarMonthsf: (Js.Date.t, Js.Date.t) => float =
  "date-fns/differenceInCalendarMonths"
@module
external differenceInMonths: (Js.Date.t, Js.Date.t) => int = "date-fns/differenceInMonths"
@module
external differenceInMonthsf: (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInMonths"
@module
external eachWeekendOfMonth: Js.Date.t => array<Js.Date.t> = "date-fns/eachWeekendOfMonth"

@module external endOfMonth: Js.Date.t => Js.Date.t = "date-fns/endOfMonth"
@module external getDaysInMonth: Js.Date.t => int = "date-fns/getDaysInMonth"
@module external getDaysInMonthf: Js.Date.t => float = "date-fns/getDaysInMonth"
@module external getMonth: Js.Date.t => int = "date-fns/getMonth"
@module external getMonthf: Js.Date.t => float = "date-fns/getMonth"
@module external isFirstDayOfMonth: Js.Date.t => bool = "date-fns/isFirstDayOfMonth"
@module external isLastDayOfMonth: Js.Date.t => bool = "date-fns/isLastDayOfMonth"
@module external isSameMonth: (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameMonth"
@module external isThisMonth: Js.Date.t => bool = "date-fns/isThisMonth"
@module external lastDayOfMonth: Js.Date.t => Js.Date.t = "date-fns/lastDayOfMonth"
@module external setMonth: (Js.Date.t, int) => Js.Date.t = "date-fns/setMonth"
@module external setMonthf: (Js.Date.t, float) => Js.Date.t = "date-fns/setMonth"
@module external startOfMonth: Js.Date.t => Js.Date.t = "date-fns/startOfMonth"
@module external subMonths: (Js.Date.t, int) => Js.Date.t = "date-fns/subMonths"
@module external subMonthsf: (Js.Date.t, float) => Js.Date.t = "date-fns/subMonths"

// Quarter Helpers
@module external addQuarters: (Js.Date.t, int) => Js.Date.t = "date-fns/addQuarters"
@module external addQuartersf: (Js.Date.t, float) => Js.Date.t = "date-fns/addQuarters"
@module
external differenceInCalendarQuarters: (Js.Date.t, Js.Date.t) => int =
  "date-fns/differenceInCalendarQuarters"
@module
external differenceInCalendarQuartersf: (Js.Date.t, Js.Date.t) => float =
  "date-fns/differenceInCalendarQuarters"
@module
external differenceInQuarters: (Js.Date.t, Js.Date.t) => int = "date-fns/differenceInQuarters"
@module
external differenceInQuartersf: (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInQuarters"
@module external endOfQuarter: Js.Date.t => Js.Date.t = "date-fns/endOfQuarter"
@module external getQuarter: Js.Date.t => int = "date-fns/getQuarter"
@module external getQuarterf: Js.Date.t => float = "date-fns/getQuarter"
@module external isSameQuarter: (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameQuarter"
@module external isThisQuarter: Js.Date.t => bool = "date-fns/isThisQuarter"
@module external lastDayOfQuarter: Js.Date.t => Js.Date.t = "date-fns/lastDayOfQuarter"
type lastDayOfQuarterOptions = {additionalDigits: option<int>}

@module
external lastDayOfQuarterOpt: (Js.Date.t, lastDayOfQuarterOptions) => Js.Date.t =
  "date-fns/lastDayOfQuarter"
@module external setQuarter: (Js.Date.t, int) => Js.Date.t = "date-fns/setQuarter"
@module external setQuarterf: (Js.Date.t, float) => Js.Date.t = "date-fns/setQuarter"
@module external startOfQuarter: Js.Date.t => Js.Date.t = "date-fns/startOfQuarter"
@module external subQuarters: (Js.Date.t, int) => Js.Date.t = "date-fns/subQuarters"
@module external subQuartersf: (Js.Date.t, float) => Js.Date.t = "date-fns/subQuarters"

// Year Helpers
@module external addYears: (Js.Date.t, int) => Js.Date.t = "date-fns/addYears"
@module external addYearsf: (Js.Date.t, float) => Js.Date.t = "date-fns/addYears"
@module
external differenceInCalendarYears: (Js.Date.t, Js.Date.t) => int =
  "date-fns/differenceInCalendarYears"
@module
external differenceInCalendarYearsf: (Js.Date.t, Js.Date.t) => float =
  "date-fns/differenceInCalendarYears"
@module
external differenceInYears: (Js.Date.t, Js.Date.t) => int = "date-fns/differenceInYears"
@module
external differenceInYearsf: (Js.Date.t, Js.Date.t) => float = "date-fns/differenceInYears"
@module
external eachWeekendOfYear: Js.Date.t => array<Js.Date.t> = "date-fns/eachWeekendOfYear"
@module external endOfYear: Js.Date.t => Js.Date.t = "date-fns/endOfYear"
@module external getDaysInYear: Js.Date.t => int = "date-fns/getDaysInYear"
@module external getDaysInYearf: Js.Date.t => float = "date-fns/getDaysInYear"
@module external getYear: Js.Date.t => int = "date-fns/getYear"
@module external getYearf: Js.Date.t => float = "date-fns/getYear"
@module external isLeapYear: Js.Date.t => bool = "date-fns/isLeapYear"
@module external isSameYear: (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameYear"
@module external isThisYear: Js.Date.t => bool = "date-fns/isThisYear"
@module external lastDayOfYear: Js.Date.t => Js.Date.t = "date-fns/lastDayOfYear"
@module external setYear: (Js.Date.t, int) => Js.Date.t = "date-fns/setYear"
@module external setYearf: (Js.Date.t, float) => Js.Date.t = "date-fns/setYear"
@module external startOfYear: Js.Date.t => Js.Date.t = "date-fns/startOfYear"
@module external subYears: (Js.Date.t, int) => Js.Date.t = "date-fns/subYears"
@module external subYearsf: (Js.Date.t, float) => Js.Date.t = "date-fns/subYears"

// ISO Week-Numbering Year Helpers
@module
external addISOWeekYears: (Js.Date.t, int) => Js.Date.t = "date-fns/addISOWeekYears"
@module
external addISOWeekYearsf: (Js.Date.t, float) => Js.Date.t = "date-fns/addISOWeekYears"
@module
external differenceInCalendarISOWeekYears: (Js.Date.t, Js.Date.t) => int =
  "date-fns/differenceInCalendarISOWeekYears"

@module
external differenceInCalendarISOWeekYearsf: (Js.Date.t, Js.Date.t) => float =
  "date-fns/differenceInCalendarISOWeekYears"
@module
external differenceInISOWeekYears: (Js.Date.t, Js.Date.t) => int =
  "date-fns/differenceInISOWeekYears"
@module
external differenceInISOWeekYearsf: (Js.Date.t, Js.Date.t) => float =
  "date-fns/differenceInISOWeekYears"
@module external endOfISOWeekYear: Js.Date.t => Js.Date.t = "date-fns/endOfISOWeekYear"
@module external getISOWeekYear: Js.Date.t => int = "date-fns/getISOWeekYear"
@module external getISOWeekYearf: Js.Date.t => float = "date-fns/getISOWeekYear"
@module external getISOWeeksInYear: Js.Date.t => int = "date-fns/getISOWeeksInYear"
@module external getISOWeeksInYearf: Js.Date.t => float = "date-fns/getISOWeeksInYear"
@module
external isSameISOWeekYear: (Js.Date.t, Js.Date.t) => bool = "date-fns/isSameISOWeekYear"
@module
external lastDayOfISOWeekYear: Js.Date.t => Js.Date.t = "date-fns/lastDayOfISOWeekYear"
@module
external setISOWeekYear: (Js.Date.t, int) => Js.Date.t = "date-fns/setISOWeekYear"
@module
external setISOWeekYearf: (Js.Date.t, float) => Js.Date.t = "date-fns/setISOWeekYear"
@module
external startOfISOWeekYear: Js.Date.t => Js.Date.t = "date-fns/startOfISOWeekYear"
@module
external subISOWeekYears: (Js.Date.t, int) => Js.Date.t = "date-fns/subISOWeekYears"
@module
external subISOWeekYearsf: (Js.Date.t, float) => Js.Date.t = "date-fns/subISOWeekYears"

// Decade Helpers
@module external endOfDecade: Js.Date.t => Js.Date.t = "date-fns/endOfDecade"
type endOfDecadeOptions = {additionalDigits: option<int>}
@module
external endOfDecadeOpt: (Js.Date.t, endOfDecadeOptions) => Js.Date.t = "date-fns/endOfDecade"
@module external getDecade: Js.Date.t => int = "date-fns/getDecade"
@module external getDecadef: Js.Date.t => float = "date-fns/getDecade"
@module external lastDayOfDecade: Js.Date.t => Js.Date.t = "date-fns/lastDayOfDecade"
@module external startOfDecade: Js.Date.t => Js.Date.t = "date-fns/startOfDecade"

// Week-Numbering Year Helpers
type weekYearOptions = {
  locale: option<locale>,
  weekStartsOn: option<int>,
  firstWeekContainsDate: option<int>,
}
@module external getWeekYear: Js.Date.t => int = "date-fns/getWeekYear"
@module
external getWeekYearOpt: (Js.Date.t, weekYearOptions) => int = "date-fns/getWeekYear"
@module external getWeekYearf: Js.Date.t => float = "date-fns/getWeekYear"
@module
external getWeekYearOptf: (Js.Date.t, weekYearOptions) => float = "date-fns/getWeekYear"
@module external setWeekYear: (Js.Date.t, int) => Js.Date.t = "date-fns/setWeekYear"
@module
external setWeekYearOpt: (Js.Date.t, int, weekYearOptions) => Js.Date.t = "date-fns/setWeekYear"
@module external setWeekYearf: (Js.Date.t, float) => Js.Date.t = "date-fns/setWeekYear"
@module
external setWeekYearOptf: (Js.Date.t, float, weekYearOptions) => Js.Date.t = "date-fns/setWeekYear"
@module external startOfWeekYear: Js.Date.t => Js.Date.t = "date-fns/startOfWeekYear"
@module
external startOfWeekYearOpt: (Js.Date.t, weekYearOptions) => Js.Date.t = "date-fns/startOfWeekYear"
