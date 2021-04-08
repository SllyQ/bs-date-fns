type interval = {
  start: Js.Date.t,
  @as("end")
  end_: Js.Date.t,
}

type locale

// Common Helpers
@module("date-fns")
external closestIndexTo: (Js.Date.t, array<Js.Date.t>) => int = "closestIndexTo"
@module("date-fns")
external closestTo: (Js.Date.t, array<Js.Date.t>) => Js.Date.t = "closestTo"
@module("date-fns") external compareAsc: (Js.Date.t, Js.Date.t) => int = "compareAsc"

@module("date-fns") external compareDesc: (Js.Date.t, Js.Date.t) => int = "compareDesc"

@module("date-fns") external format: (Js.Date.t, string) => string = "format"
type formatOptions = {
  locale: option<locale>,
  weekStartsOn: option<int>,
  firstWeekContainsDate: option<int>,
  useAdditionalWeekYearTokens: option<bool>,
  useAdditionalDayOfYearTokens: option<bool>,
}
@module("date-fns")
external formatOpt: (Js.Date.t, string, formatOptions) => string = "formatOpt"

@module("date-fns")
external formatDistance: (Js.Date.t, Js.Date.t) => string = "formatDistance"
type formatDistanceOptions = {
  includeSeconds: option<bool>,
  addSuffix: option<bool>,
  locale: option<locale>,
}
@module("date-fns")
external formatDistanceOpt: (Js.Date.t, Js.Date.t, formatDistanceOptions) => string =
  "formatDistance"
@module("date-fns")
external formatDistanceStrict: (Js.Date.t, Js.Date.t) => string = "formatDistanceStrict"
type formatDistanceStrictOptions = {
  addSuffix: option<bool>,
  unit: option<string>,
  roundingMethod: option<string>,
  locale: option<locale>,
}
@module("date-fns")
external formatDistanceStrictOpt: (Js.Date.t, Js.Date.t, formatDistanceStrictOptions) => string =
  "formatDistanceStrict"
@module("date-fns")
external formatDistanceToNow: Js.Date.t => string = "formatDistanceToNow"
type formatDistanceToNowOptions = {
  includeSeconds: option<bool>,
  addSuffix: option<bool>,
  locale: option<locale>,
}
@module("date-fns")
external formatDistanceToNowOpt: (Js.Date.t, formatDistanceToNowOptions) => string =
  "formatDistanceToNow"

@module("date-fns")
external formatISO: Js.Date.t => string = "formatISO"
type formatISOOptions = {
  format: option<string>,
  representation: option<string>,
}

@module("date-fns")
external formatISOOpt: (Js.Date.t, formatISOOptions) => string = "formatISO"

@module("date-fns")
external formatISO9075: Js.Date.t => string = "formatISO9075"
type formatISO9075Options = {
  format: option<string>,
  representation: option<string>,
}

@module("date-fns")
external formatISO9075Opt: (Js.Date.t, formatISO9075Options) => string = "formatISO9075"

@module("date-fns") external formatRFC3339: Js.Date.t => string = "formatRFC3339"
type formatRFC3339Options = {fractionDigits: option<int>}

@module("date-fns")
external formatRFC3339Options: (Js.Date.t, formatRFC3339Options) => string = "formatRFC3339"

@module("date-fns") external formatRFC7231: Js.Date.t => string = "formatRFC7231"

@module("date-fns")
external formatRelative: (Js.Date.t, Js.Date.t) => string = "formatRelative"
type formatRelativeOptions = {
  locale: option<locale>,
  weekStartsOn: option<int>,
}
@module("date-fns")
external formatRelativeOpt: (Js.Date.t, Js.Date.t, formatRelativeOptions) => string =
  "formatRelative"

@module("date-fns") external isAfter: (Js.Date.t, Js.Date.t) => bool = "isAfter"
@module("date-fns") external isBefore: (Js.Date.t, Js.Date.t) => bool = "isBefore"
@module("date-fns") external isDate: 'a => bool = "isDate"
@module("date-fns") external isEqual: (Js.Date.t, Js.Date.t) => bool = "isEqual"
@module("date-fns") external isFuture: Js.Date.t => bool = "isFuture"
@module("date-fns") external isPast: Js.Date.t => bool = "isPast"
@module("date-fns") external isValid: 'a => bool = "isValid"
@module("date-fns") external lightFormat: (Js.Date.t, string) => string = "lightFormat"
@module("date-fns") external max: array<Js.Date.t> => Js.Date.t = "max"
@module("date-fns") external min: array<Js.Date.t> => Js.Date.t = "min"
@module("date-fns") external parse: (string, string, Js.Date.t) => Js.Date.t = "parse"
type parseOptions = {
  locale: option<locale>,
  weekStartsOn: option<int>,
  firstWeekContainsDate: option<int>,
  useAdditionalWeekYearTokens: option<bool>,
  useAdditionalDayOfYearTokens: option<bool>,
}
@module("date-fns")
external parseOpt: (string, string, Js.Date.t, parseOptions) => Js.Date.t = "parse"
@module("date-fns") external parseISO: string => Js.Date.t = "parseISO"
type parseISOOptions = {additionalDigits: option<int>}
@module("date-fns")
external parseISOOpt: (string, parseISOOptions) => Js.Date.t = "parseISO"
@module("date-fns") external parseJSONString: string => Js.Date.t = "parseJSON"
@module("date-fns") external parseJSONFloat: float => Js.Date.t = "parseJSON"
@module("date-fns") external parseJSONInt: int => Js.Date.t = "parseJSON"
type setOptions = {
  year: option<int>,
  month: option<int>,
  date: option<int>,
  hours: option<int>,
  minutes: option<int>,
  seconds: option<int>,
  milliseconds: option<int>,
}
@module("date-fns") external set: (Js.Date.t, setOptions) => Js.Date.t = "set"
@module("date-fns") external toDateFloat: float => Js.Date.t = "toDate"
@module("date-fns") external toDateInt: int => Js.Date.t = "toDate"

// Interval Helpers

@module("date-fns")
external areIntervalsOverlapping: (interval, interval) => bool = "areIntervalsOverlapping"

@module("date-fns")
external eachDayOfInterval: interval => array<Js.Date.t> = "eachDayOfInterval"

type eachDayOfIntervalOptions = {step: option<int>}
@module("date-fns")
external eachDayOfIntervalOpt: (interval, eachDayOfIntervalOptions) => array<Js.Date.t> =
  "eachDayOfInterval"

@module("date-fns")
external eachWeekOfInterval: interval => array<Js.Date.t> = "eachWeekOfInterval"
type eachWeekOfIntervalOptions = {
  locale: option<locale>,
  weekStartsOn: option<int>,
}
@module("date-fns")
external eachWeekOfIntervalOpt: (interval, eachWeekOfIntervalOptions) => array<Js.Date.t> =
  "eachWeekOfInterval"

@module("date-fns")
external eachWeekendOfInterval: interval => array<Js.Date.t> = "eachWeekendOfInterval"

@module("date-fns")
external getOverlappingDaysInIntervals: (interval, interval) => int =
  "getOverlappingDaysInIntervals"
@module("date-fns")
external getOverlappingDaysInIntervalsf: (interval, interval) => float =
  "getOverlappingDaysInIntervals"
@module("date-fns")
external isWithinInterval: (Js.Date.t, interval) => bool = "isWithinInterval"

// Timestamp Helpers
@module("date-fns") external fromUnixTime: float => Js.Date.t = "fromUnixTime"
@module("date-fns") external getTime: Js.Date.t => float = "getTime"
@module("date-fns") external getUnixTime: Js.Date.t => float = "getUnixTime"

// Millisecond Helpers
@module("date-fns")
external addMilliseconds: (Js.Date.t, int) => Js.Date.t = "addMilliseconds"
@module("date-fns")
external addMillisecondsf: (Js.Date.t, float) => Js.Date.t = "addMilliseconds"
@module("date-fns")
external differenceInMilliseconds: (Js.Date.t, Js.Date.t) => int = "differenceInMilliseconds"
@module("date-fns")
external differenceInMillisecondsf: (Js.Date.t, Js.Date.t) => float = "differenceInMilliseconds"
@module("date-fns") external getMilliseconds: Js.Date.t => int = "getMilliseconds"
@module("date-fns") external getMillisecondsf: Js.Date.t => float = "getMilliseconds"
@module("date-fns")
external setMilliseconds: (Js.Date.t, int) => Js.Date.t = "setMilliseconds"
@module("date-fns")
external setMillisecondsf: (Js.Date.t, float) => Js.Date.t = "setMilliseconds"
@module("date-fns")
external subMilliseconds: (Js.Date.t, int) => Js.Date.t = "subMilliseconds"
@module("date-fns")
external subMillisecondsf: (Js.Date.t, float) => Js.Date.t = "subMilliseconds"

// Second Helpers
@module("date-fns") external addSeconds: (Js.Date.t, int) => Js.Date.t = "addSeconds"
@module("date-fns") external addSecondsf: (Js.Date.t, float) => Js.Date.t = "addSeconds"
@module("date-fns")
external differenceInSeconds: (Js.Date.t, Js.Date.t) => int = "differenceInSeconds"
@module("date-fns")
external differenceInSecondsf: (Js.Date.t, Js.Date.t) => float = "differenceInSeconds"
@module("date-fns") external endOfSecond: Js.Date.t => Js.Date.t = "endOfSecond"
@module("date-fns") external getSeconds: Js.Date.t => int = "getSeconds"
@module("date-fns") external getSecondsf: Js.Date.t => float = "getSeconds"
@module("date-fns") external isSameSecond: (Js.Date.t, Js.Date.t) => bool = "isSameSecond"
@module("date-fns") external isThisSecond: Js.Date.t => bool = "isThisSecond"
@module("date-fns") external setSeconds: (Js.Date.t, int) => Js.Date.t = "setSeconds"
@module("date-fns") external setSecondsf: (Js.Date.t, float) => Js.Date.t = "setSeconds"
@module("date-fns") external startOfSecond: Js.Date.t => Js.Date.t = "startOfSecond"
@module("date-fns") external subSeconds: (Js.Date.t, int) => Js.Date.t = "subSeconds"
@module("date-fns") external subSecondsf: (Js.Date.t, float) => Js.Date.t = "subSeconds"

// Minute Helpers
@module("date-fns") external addMinutes: (Js.Date.t, int) => Js.Date.t = "addMinutes"
@module("date-fns") external addMinutesf: (Js.Date.t, float) => Js.Date.t = "addMinutes"
@module("date-fns")
external differenceInMinutes: (Js.Date.t, Js.Date.t) => int = "differenceInMinutes"
@module("date-fns")
external differenceInMinutesf: (Js.Date.t, Js.Date.t) => float = "differenceInMinutes"
@module("date-fns") external endOfMinute: Js.Date.t => Js.Date.t = "endOfMinute"
@module("date-fns") external getMinutes: Js.Date.t => int = "getMinutes"
@module("date-fns") external getMinutesf: Js.Date.t => float = "getMinutes"
@module("date-fns") external isSameMinute: (Js.Date.t, Js.Date.t) => bool = "isSameMinute"
@module("date-fns") external isThisMinute: Js.Date.t => bool = "isThisMinute"

@module("date-fns")
external roundToNearestMinutes: Js.Date.t => Js.Date.t = "roundToNearestMinutes"
type roundToNearestMinutesOptions = {nearestTo: option<int>}

@module("date-fns")
external roundToNearestMinutesOpt: (Js.Date.t, roundToNearestMinutesOptions) => Js.Date.t =
  "roundToNearestMinutes"
@module("date-fns") external setMinutes: (Js.Date.t, int) => Js.Date.t = "setMinutes"
@module("date-fns") external startOfMinute: Js.Date.t => Js.Date.t = "startOfMinute"
@module("date-fns") external subMinutes: (Js.Date.t, int) => Js.Date.t = "subMinutes"
@module("date-fns") external subMinutesf: (Js.Date.t, float) => Js.Date.t = "subMinutes"

// Hour Helpers
@module("date-fns") external addHours: (Js.Date.t, int) => Js.Date.t = "addHours"
@module("date-fns") external addHoursf: (Js.Date.t, float) => Js.Date.t = "addHours"
@module("date-fns")
external differenceInHours: (Js.Date.t, Js.Date.t) => int = "differenceInHours"
@module("date-fns")
external differenceInHoursf: (Js.Date.t, Js.Date.t) => float = "differenceInHours"
@module("date-fns") external endOfHour: Js.Date.t => Js.Date.t = "endOfHour"
@module("date-fns") external getHours: Js.Date.t => int = "getHours"
@module("date-fns") external getHoursf: Js.Date.t => float = "getHours"
@module("date-fns") external isSameHour: (Js.Date.t, Js.Date.t) => bool = "isSameHour"
@module("date-fns") external isThisHour: Js.Date.t => bool = "isThisHour"
@module("date-fns") external setHours: (Js.Date.t, int) => Js.Date.t = "setHours"
@module("date-fns") external setHoursf: (Js.Date.t, float) => Js.Date.t = "setHours"
@module("date-fns") external startOfHour: Js.Date.t => Js.Date.t = "startOfHour"
@module("date-fns") external subHours: (Js.Date.t, int) => Js.Date.t = "subHours"
@module("date-fns") external subHoursf: (Js.Date.t, float) => Js.Date.t = "subHours"

// Day Helpers
@module("date-fns")
external addBusinessDays: (Js.Date.t, int) => Js.Date.t = "addBusinessDays"
@module("date-fns")
external addBusinessDaysf: (Js.Date.t, float) => Js.Date.t = "addBusinessDays"
@module("date-fns") external addDays: (Js.Date.t, int) => Js.Date.t = "addDays"
@module("date-fns") external addDaysf: (Js.Date.t, float) => Js.Date.t = "addDays"
@module("date-fns")
external differenceInBusinessDays: (Js.Date.t, Js.Date.t) => int = "differenceInBusinessDays"
@module("date-fns")
external differenceInBusinessDaysf: (Js.Date.t, Js.Date.t) => float = "differenceInBusinessDays"
@module("date-fns")
external differenceInCalendarDays: (Js.Date.t, Js.Date.t) => int = "differenceInCalendarDays"
@module("date-fns")
external differenceInCalendarDaysf: (Js.Date.t, Js.Date.t) => float = "differenceInCalendarDays"
@module("date-fns")
external differenceInDays: (Js.Date.t, Js.Date.t) => int = "differenceInDays"
@module("date-fns")
external differenceInDaysf: (Js.Date.t, Js.Date.t) => float = "differenceInDays"
@module("date-fns") external endOfDay: Js.Date.t => Js.Date.t = "endOfDay"
@module("date-fns") external endOfToday: unit => Js.Date.t = "endOfToday"
@module("date-fns") external endOfTomorrow: unit => Js.Date.t = "endOfTomorrow"
@module("date-fns") external endOfYesterday: unit => Js.Date.t = "endOfYesterday"
@module("date-fns") external getDate: Js.Date.t => int = "getDate"
@module("date-fns") external getDatef: Js.Date.t => float = "getDate"
@module("date-fns") external getDayOfYear: Js.Date.t => int = "getDayOfYear"
@module("date-fns") external getDayOfYearf: Js.Date.t => float = "getDayOfYear"
@module("date-fns") external isSameDay: (Js.Date.t, Js.Date.t) => bool = "isSameDay"
@module("date-fns") external isToday: Js.Date.t => bool = "isToday"
@module("date-fns") external isTomorrow: Js.Date.t => bool = "isTomorrow"
@module("date-fns") external isYesterday: Js.Date.t => bool = "isYesterday"
@module("date-fns") external setDate: (Js.Date.t, int) => Js.Date.t = "setDate"
@module("date-fns") external setDatef: (Js.Date.t, float) => Js.Date.t = "setDate"
@module("date-fns") external setDayOfYear: (Js.Date.t, int) => Js.Date.t = "setDayOfYear"
@module("date-fns") external setDayOfYearf: (Js.Date.t, float) => Js.Date.t = "setDayOfYear"
@module("date-fns") external startOfDay: Js.Date.t => Js.Date.t = "startOfDay"
@module("date-fns") external startOfToday: unit => Js.Date.t = "startOfToday"
@module("date-fns") external startOfTomorrow: unit => Js.Date.t = "startOfTomorrow"
@module("date-fns") external startOfYesterday: unit => Js.Date.t = "startOfYesterday"
@module("date-fns")
external subBusinessDays: (Js.Date.t, int) => Js.Date.t = "subBusinessDays"
@module("date-fns")
external subBusinessDaysf: (Js.Date.t, float) => Js.Date.t = "subBusinessDays"
@module("date-fns/subDays") external subDays: (Js.Date.t, int) => Js.Date.t = "default"
@module("date-fns/subDays") external subDaysf: (Js.Date.t, float) => Js.Date.t = "default"

// Weekday Helpers
@module("date-fns") external getDay: Js.Date.t => int = "getDay"
@module("date-fns") external getDayf: Js.Date.t => float = "getDay"
@module("date-fns") external getISODay: Js.Date.t => int = "getISODay"
@module("date-fns") external getISODayf: Js.Date.t => float = "getISODay"
@module("date-fns") external isFriday: Js.Date.t => bool = "isFriday"
@module("date-fns") external isMonday: Js.Date.t => bool = "isMonday"
@module("date-fns") external isSaturday: Js.Date.t => bool = "isSaturday"
@module("date-fns") external isSunday: Js.Date.t => bool = "isSunday"
@module("date-fns") external isThursday: Js.Date.t => bool = "isThursday"
@module("date-fns") external isTuesday: Js.Date.t => bool = "isTuesday"
@module("date-fns") external isWednesday: Js.Date.t => bool = "isWednesday"
@module("date-fns") external isWeekend: Js.Date.t => bool = "isWeekend"
@module("date-fns") external setDay: (Js.Date.t, int) => Js.Date.t = "setDay"
@module("date-fns") external setDayf: (Js.Date.t, float) => Js.Date.t = "setDay"
type setDayOptions = {
  locale: option<locale>,
  weekStartsOn: option<int>,
}
@module("date-fns")
external setDayOpt: (Js.Date.t, int, setDayOptions) => Js.Date.t = "setDay"
@module("date-fns")
external setDayOptf: (Js.Date.t, float, setDayOptions) => Js.Date.t = "setDay"
@module("date-fns") external setISODay: (Js.Date.t, int) => Js.Date.t = "setISODay"
@module("date-fns") external setISODayf: (Js.Date.t, float) => Js.Date.t = "setISODay"

// Week Helpers
type weekOptions = {
  locale: option<locale>,
  weekStartsOn: option<int>,
}
@module("date-fns") external addWeeks: (Js.Date.t, int) => Js.Date.t = "addWeeks"
@module("date-fns") external addWeeksf: (Js.Date.t, float) => Js.Date.t = "addWeeks"

@module("date-fns")
external differenceInCalendarWeeks: (Js.Date.t, Js.Date.t) => int = "differenceInCalendarWeeks"

@module("date-fns")
external differenceInCalendarWeeksOpt: (Js.Date.t, Js.Date.t, weekOptions) => int =
  "differenceInCalendarWeeks"

@module("date-fns")
external differenceInCalendarWeeksf: (Js.Date.t, Js.Date.t) => float = "differenceInCalendarWeeks"

@module("date-fns")
external differenceInCalendarWeeksOptf: (Js.Date.t, Js.Date.t, weekOptions) => float =
  "differenceInCalendarWeeks"

@module("date-fns")
external differenceInWeeks: (Js.Date.t, Js.Date.t) => int = "differenceInWeeks"
@module("date-fns")
external differenceInWeeksf: (Js.Date.t, Js.Date.t) => float = "differenceInWeeks"
@module("date-fns") external endOfWeek: Js.Date.t => Js.Date.t = "endOfWeek"
@module("date-fns")
external endOfWeekOpt: (Js.Date.t, weekOptions) => Js.Date.t = "endOfWeek"

@module("date-fns") external getWeek: Js.Date.t => int = "getWeek"
@module("date-fns") external getWeekf: Js.Date.t => float = "getWeek"
type getWeekOptions = {
  locale: option<locale>,
  weekStartsOn: option<int>,
  firstWeekContainsDate: option<int>,
}
@module("date-fns") external getWeekOpt: (Js.Date.t, getWeekOptions) => int = "getWeek"
@module("date-fns") external getWeekOptf: (Js.Date.t, getWeekOptions) => float = "getWeek"
@module("date-fns") external getWeekOfMonth: Js.Date.t => int = "getWeekOfMonth"

@module("date-fns") external getWeekOfMonthf: Js.Date.t => float = "getWeekOfMonth"
external getWeekOfMonthOpt: (Js.Date.t, weekOptions) => int = "date-fns/getWeekOfMonth"

@module("date-fns")
external getWeekOfMonthOptf: (Js.Date.t, weekOptions) => float = "getWeekOfMonth"
@module("date-fns") external getWeeksInMonth: Js.Date.t => int = "getWeeksInMonth"
@module("date-fns") external getWeeksInMonthf: Js.Date.t => float = "getWeeksInMonth"
external getWeeksInMonthOpt: (Js.Date.t, weekOptions) => int = "date-fns/getWeeksInMonth"
@module("date-fns")
external getWeeksInMonthOptf: (Js.Date.t, weekOptions) => float = "getWeeksInMonth"

@module("date-fns") external isSameWeek: (Js.Date.t, Js.Date.t) => bool = "isSameWeek"
@module("date-fns")
external isSameWeekOpt: (Js.Date.t, Js.Date.t, weekOptions) => bool = "isSameWeek"
@module("date-fns") external isThisWeek: Js.Date.t => bool = "isThisWeek"
@module("date-fns") external isThisWeekOpt: (Js.Date.t, weekOptions) => bool = "isThisWeek"
@module("date-fns") external lastDayOfWeek: Js.Date.t = "lastDayOfWeek"
@module("date-fns") external lastDayOfWeekOpt: (Js.Date.t, weekOptions) = "lastDayOfWeek"
@module("date-fns") external setWeek: (Js.Date.t, int) => Js.Date.t = "setWeek"
@module("date-fns") external setWeekf: (Js.Date.t, float) => Js.Date.t = "setWeek"
type setWeekOptions = {
  locale: option<locale>,
  weekStartsOn: option<int>,
  firstWeekContainsDate: option<int>,
}
@module("date-fns")
external setWeekOpt: (Js.Date.t, int, setWeekOptions) => Js.Date.t = "setWeek"
@module("date-fns")
external setWeekOptf: (Js.Date.t, float, setWeekOptions) => Js.Date.t = "setWeek"
@module("date-fns") external startOfWeek: Js.Date.t => Js.Date.t = "startOfWeek"
@module("date-fns")
external startOfWeekOpt: (Js.Date.t, weekOptions) => Js.Date.t = "startOfWeek"
@module("date-fns") external subWeeks: (Js.Date.t, int) => Js.Date.t = "subWeeks"
@module("date-fns") external subWeeksf: (Js.Date.t, float) => Js.Date.t = "subWeeks"

// ISO Week Helpers
@module("date-fns")
external differenceInCalendarISOWeeks: (Js.Date.t, Js.Date.t) => int =
  "differenceInCalendarISOWeeks"
@module("date-fns")
external differenceInCalendarISOWeeksf: (Js.Date.t, Js.Date.t) => float =
  "differenceInCalendarISOWeeks"
@module("date-fns") external endOfISOWeek: Js.Date.t => Js.Date.t = "endOfISOWeek"
@module("date-fns") external getISOWeek: Js.Date.t => int = "getISOWeek"
@module("date-fns") external getISOWeekf: Js.Date.t => float = "getISOWeek"
@module("date-fns") external isSameISOWeek: (Js.Date.t, Js.Date.t) => bool = "isSameISOWeek"
@module("date-fns") external isThisISOWeek: Js.Date.t => bool = "isThisISOWeek"
@module("date-fns") external lastDayOfISOWeek: Js.Date.t => Js.Date.t = "lastDayOfISOWeek"
@module("date-fns") external setISOWeek: (Js.Date.t, int) => Js.Date.t = "setISOWeek"
@module("date-fns") external setISOWeekf: (Js.Date.t, float) => Js.Date.t = "setISOWeek"
@module("date-fns") external startOfISOWeek: Js.Date.t => Js.Date.t = "startOfISOWeek"

// Month Helpers
@module("date-fns") external addMonths: (Js.Date.t, int) => Js.Date.t = "addMonths"
@module("date-fns") external addMonthsf: (Js.Date.t, float) => Js.Date.t = "addMonths"
@module("date-fns")
external differenceInCalendarMonths: (Js.Date.t, Js.Date.t) => int = "differenceInCalendarMonths"
@module("date-fns")
external differenceInCalendarMonthsf: (Js.Date.t, Js.Date.t) => float = "differenceInCalendarMonths"
@module("date-fns")
external differenceInMonths: (Js.Date.t, Js.Date.t) => int = "differenceInMonths"
@module("date-fns")
external differenceInMonthsf: (Js.Date.t, Js.Date.t) => float = "differenceInMonths"
@module("date-fns")
external eachWeekendOfMonth: Js.Date.t => array<Js.Date.t> = "eachWeekendOfMonth"

@module("date-fns") external endOfMonth: Js.Date.t => Js.Date.t = "endOfMonth"
@module("date-fns") external getDaysInMonth: Js.Date.t => int = "getDaysInMonth"
@module("date-fns") external getDaysInMonthf: Js.Date.t => float = "getDaysInMonth"
@module("date-fns") external getMonth: Js.Date.t => int = "getMonth"
@module("date-fns") external getMonthf: Js.Date.t => float = "getMonth"
@module("date-fns") external isFirstDayOfMonth: Js.Date.t => bool = "isFirstDayOfMonth"
@module("date-fns") external isLastDayOfMonth: Js.Date.t => bool = "isLastDayOfMonth"
@module("date-fns") external isSameMonth: (Js.Date.t, Js.Date.t) => bool = "isSameMonth"
@module("date-fns") external isThisMonth: Js.Date.t => bool = "isThisMonth"
@module("date-fns") external lastDayOfMonth: Js.Date.t => Js.Date.t = "lastDayOfMonth"
@module("date-fns") external setMonth: (Js.Date.t, int) => Js.Date.t = "setMonth"
@module("date-fns") external setMonthf: (Js.Date.t, float) => Js.Date.t = "setMonth"
@module("date-fns") external startOfMonth: Js.Date.t => Js.Date.t = "startOfMonth"
@module("date-fns") external subMonths: (Js.Date.t, int) => Js.Date.t = "subMonths"
@module("date-fns") external subMonthsf: (Js.Date.t, float) => Js.Date.t = "subMonths"

// Quarter Helpers
@module("date-fns") external addQuarters: (Js.Date.t, int) => Js.Date.t = "addQuarters"
@module("date-fns") external addQuartersf: (Js.Date.t, float) => Js.Date.t = "addQuarters"
@module("date-fns")
external differenceInCalendarQuarters: (Js.Date.t, Js.Date.t) => int =
  "differenceInCalendarQuarters"
@module("date-fns")
external differenceInCalendarQuartersf: (Js.Date.t, Js.Date.t) => float =
  "differenceInCalendarQuarters"
@module("date-fns")
external differenceInQuarters: (Js.Date.t, Js.Date.t) => int = "differenceInQuarters"
@module("date-fns")
external differenceInQuartersf: (Js.Date.t, Js.Date.t) => float = "differenceInQuarters"
@module("date-fns") external endOfQuarter: Js.Date.t => Js.Date.t = "endOfQuarter"
@module("date-fns") external getQuarter: Js.Date.t => int = "getQuarter"
@module("date-fns") external getQuarterf: Js.Date.t => float = "getQuarter"
@module("date-fns") external isSameQuarter: (Js.Date.t, Js.Date.t) => bool = "isSameQuarter"
@module("date-fns") external isThisQuarter: Js.Date.t => bool = "isThisQuarter"
@module("date-fns") external lastDayOfQuarter: Js.Date.t => Js.Date.t = "lastDayOfQuarter"
type lastDayOfQuarterOptions = {additionalDigits: option<int>}

@module("date-fns")
external lastDayOfQuarterOpt: (Js.Date.t, lastDayOfQuarterOptions) => Js.Date.t = "lastDayOfQuarter"
@module("date-fns") external setQuarter: (Js.Date.t, int) => Js.Date.t = "setQuarter"
@module("date-fns") external setQuarterf: (Js.Date.t, float) => Js.Date.t = "setQuarter"
@module("date-fns") external startOfQuarter: Js.Date.t => Js.Date.t = "startOfQuarter"
@module("date-fns") external subQuarters: (Js.Date.t, int) => Js.Date.t = "subQuarters"
@module("date-fns") external subQuartersf: (Js.Date.t, float) => Js.Date.t = "subQuarters"

// Year Helpers
@module("date-fns") external addYears: (Js.Date.t, int) => Js.Date.t = "addYears"
@module("date-fns") external addYearsf: (Js.Date.t, float) => Js.Date.t = "addYears"
@module("date-fns")
external differenceInCalendarYears: (Js.Date.t, Js.Date.t) => int = "differenceInCalendarYears"
@module("date-fns")
external differenceInCalendarYearsf: (Js.Date.t, Js.Date.t) => float = "differenceInCalendarYears"
@module("date-fns")
external differenceInYears: (Js.Date.t, Js.Date.t) => int = "differenceInYears"
@module("date-fns")
external differenceInYearsf: (Js.Date.t, Js.Date.t) => float = "differenceInYears"
@module("date-fns")
external eachWeekendOfYear: Js.Date.t => array<Js.Date.t> = "eachWeekendOfYear"
@module("date-fns") external endOfYear: Js.Date.t => Js.Date.t = "endOfYear"
@module("date-fns") external getDaysInYear: Js.Date.t => int = "getDaysInYear"
@module("date-fns") external getDaysInYearf: Js.Date.t => float = "getDaysInYear"
@module("date-fns") external getYear: Js.Date.t => int = "getYear"
@module("date-fns") external getYearf: Js.Date.t => float = "getYear"
@module("date-fns") external isLeapYear: Js.Date.t => bool = "isLeapYear"
@module("date-fns") external isSameYear: (Js.Date.t, Js.Date.t) => bool = "isSameYear"
@module("date-fns") external isThisYear: Js.Date.t => bool = "isThisYear"
@module("date-fns") external lastDayOfYear: Js.Date.t => Js.Date.t = "lastDayOfYear"
@module("date-fns") external setYear: (Js.Date.t, int) => Js.Date.t = "setYear"
@module("date-fns") external setYearf: (Js.Date.t, float) => Js.Date.t = "setYear"
@module("date-fns") external startOfYear: Js.Date.t => Js.Date.t = "startOfYear"
@module("date-fns") external subYears: (Js.Date.t, int) => Js.Date.t = "subYears"
@module("date-fns") external subYearsf: (Js.Date.t, float) => Js.Date.t = "subYears"

// ISO Week-Numbering Year Helpers
@module("date-fns")
external addISOWeekYears: (Js.Date.t, int) => Js.Date.t = "addISOWeekYears"
@module("date-fns")
external addISOWeekYearsf: (Js.Date.t, float) => Js.Date.t = "addISOWeekYears"
@module("date-fns")
external differenceInCalendarISOWeekYears: (Js.Date.t, Js.Date.t) => int =
  "differenceInCalendarISOWeekYears"

@module("date-fns")
external differenceInCalendarISOWeekYearsf: (Js.Date.t, Js.Date.t) => float =
  "differenceInCalendarISOWeekYears"
@module("date-fns")
external differenceInISOWeekYears: (Js.Date.t, Js.Date.t) => int = "differenceInISOWeekYears"
@module("date-fns")
external differenceInISOWeekYearsf: (Js.Date.t, Js.Date.t) => float = "differenceInISOWeekYears"
@module("date-fns") external endOfISOWeekYear: Js.Date.t => Js.Date.t = "endOfISOWeekYear"
@module("date-fns") external getISOWeekYear: Js.Date.t => int = "getISOWeekYear"
@module("date-fns") external getISOWeekYearf: Js.Date.t => float = "getISOWeekYear"
@module("date-fns") external getISOWeeksInYear: Js.Date.t => int = "getISOWeeksInYear"
@module("date-fns") external getISOWeeksInYearf: Js.Date.t => float = "getISOWeeksInYear"
@module("date-fns")
external isSameISOWeekYear: (Js.Date.t, Js.Date.t) => bool = "isSameISOWeekYear"
@module("date-fns")
external lastDayOfISOWeekYear: Js.Date.t => Js.Date.t = "lastDayOfISOWeekYear"
@module("date-fns")
external setISOWeekYear: (Js.Date.t, int) => Js.Date.t = "setISOWeekYear"
@module("date-fns")
external setISOWeekYearf: (Js.Date.t, float) => Js.Date.t = "setISOWeekYear"
@module("date-fns")
external startOfISOWeekYear: Js.Date.t => Js.Date.t = "startOfISOWeekYear"
@module("date-fns")
external subISOWeekYears: (Js.Date.t, int) => Js.Date.t = "subISOWeekYears"
@module("date-fns")
external subISOWeekYearsf: (Js.Date.t, float) => Js.Date.t = "subISOWeekYears"

// Decade Helpers
@module("date-fns") external endOfDecade: Js.Date.t => Js.Date.t = "endOfDecade"
type endOfDecadeOptions = {additionalDigits: option<int>}
@module("date-fns")
external endOfDecadeOpt: (Js.Date.t, endOfDecadeOptions) => Js.Date.t = "endOfDecade"
@module("date-fns") external getDecade: Js.Date.t => int = "getDecade"
@module("date-fns") external getDecadef: Js.Date.t => float = "getDecade"
@module("date-fns") external lastDayOfDecade: Js.Date.t => Js.Date.t = "lastDayOfDecade"
@module("date-fns") external startOfDecade: Js.Date.t => Js.Date.t = "startOfDecade"

// Week-Numbering Year Helpers
type weekYearOptions = {
  locale: option<locale>,
  weekStartsOn: option<int>,
  firstWeekContainsDate: option<int>,
}
@module("date-fns") external getWeekYear: Js.Date.t => int = "getWeekYear"
@module("date-fns")
external getWeekYearOpt: (Js.Date.t, weekYearOptions) => int = "getWeekYear"
@module("date-fns") external getWeekYearf: Js.Date.t => float = "getWeekYear"
@module("date-fns")
external getWeekYearOptf: (Js.Date.t, weekYearOptions) => float = "getWeekYear"
@module("date-fns") external setWeekYear: (Js.Date.t, int) => Js.Date.t = "setWeekYear"
@module("date-fns")
external setWeekYearOpt: (Js.Date.t, int, weekYearOptions) => Js.Date.t = "setWeekYear"
@module("date-fns") external setWeekYearf: (Js.Date.t, float) => Js.Date.t = "setWeekYear"
@module("date-fns")
external setWeekYearOptf: (Js.Date.t, float, weekYearOptions) => Js.Date.t = "setWeekYear"
@module("date-fns") external startOfWeekYear: Js.Date.t => Js.Date.t = "startOfWeekYear"
@module("date-fns")
external startOfWeekYearOpt: (Js.Date.t, weekYearOptions) => Js.Date.t = "startOfWeekYear"
