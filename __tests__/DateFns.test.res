open Jest
open DateFns
@module("date-fns/locale") external ko: DateFns.locale = "ko"

describe("DateFns Test", () => {
  open Expect

  test("ClosestIndexTo", () => {
    let dateToCompare = Js.Date.makeWithYMD(~year=2015., ~month=8., ~date=6., ())

    let datesArray = [
      Js.Date.makeWithYMD(~year=2015., ~month=0., ~date=1., ()),
      Js.Date.makeWithYMD(~year=2016., ~month=0., ~date=1., ()),
      Js.Date.makeWithYMD(~year=2017., ~month=0., ~date=0., ()),
    ]
    expect(dateToCompare->closestIndexTo(datesArray)) |> toBe(1)
  })
  test("ClsestTo", () => {
    let dateToCompare = Js.Date.makeWithYMD(~year=2015., ~month=8., ~date=6., ())

    let datesArray = [
      Js.Date.makeWithYMD(~year=2000., ~month=0., ~date=1., ()),
      Js.Date.makeWithYMD(~year=2030., ~month=0., ~date=1., ()),
    ]

    expect(dateToCompare->closestTo(datesArray)->Js.Date.toString) |> toBe(
      Js.Date.makeWithYMD(~year=2030., ~month=0., ~date=1., ())->Js.Date.toString,
    )
  })

  test("fromUnixTime", () => {
    expect(fromUnixTime(1330515499.)->Js.Date.toDateString) |> toBe("Wed Feb 29 2012")
  })

  test("isAfter", () => {
    let laterDate = Js.Date.make()
    let earlierDate = Js.Date.makeWithYMD(~year=1999., ~month=1., ~date=29., ())

    expect(laterDate->isAfter(earlierDate)) |> toBe(true)
  })

  test("formatDistanceStrictOpt", () => {
    let laterDate = Js.Date.makeWithYMD(~year=2020., ~month=1., ~date=29., ())
    let earlierDate = Js.Date.makeWithYMD(~year=1999., ~month=1., ~date=29., ())
    let distance = formatDistanceStrictOpt(
      laterDate,
      earlierDate,
      {
        addSuffix: Some(true),
        // unit must be 'second', 'minute', 'hour', 'day', 'month' or 'year'
        unit: Some(`hour`),
        // 'floor', 'ceil' or 'round'
        roundingMethod: Some("floor"),
        locale: Some(ko),
      },
    )
    expect(distance) |> toBe(`184080시간 후`)
  })

  test("formatDistanceOpt", () => {
    let laterDate = Js.Date.makeWithYMD(~year=2020., ~month=1., ~date=29., ())
    let earlierDate = Js.Date.makeWithYMD(~year=1999., ~month=1., ~date=29., ())

    let distance = formatDistanceOpt(
      laterDate,
      earlierDate,
      {
        includeSeconds: Some(false),
        addSuffix: Some(true),
        locale: Some(ko),
      },
    )

    expect(distance) |> toBe(`거의 21년 후`)
  })

  test("formatISOOpt", () => {
    let laterDate = Js.Date.makeWithYMD(~year=2020., ~month=1., ~date=29., ())

    let result = formatISOOpt(
      laterDate,
      {
        // format must be 'extended' or 'basic'
        format: Some("basic"),
        // representation must be 'date', 'time', or 'complete'
        representation: Some("complete"),
      },
    )

    expect(result) |> toBe(`20200229T000000+09:00`)
  })

  test("min", () => {
    let date1 = Js.Date.makeWithYMD(~year=2020., ~month=1., ~date=29., ())
    let date2 = Js.Date.makeWithYMD(~year=2020., ~month=1., ~date=30., ())
    let date3 = Js.Date.makeWithYMD(~year=2020., ~month=1., ~date=31., ())

    expect([date1, date2, date3]->min) |> toEqual(
      Js.Date.makeWithYMD(~year=2020., ~month=1., ~date=29., ()),
    )
  })

  test("areIntervalsOverlapping", () => {
    let date1 = Js.Date.makeWithYMD(~year=2020., ~month=1., ~date=30., ())
    let date2 = Js.Date.makeWithYMD(~year=2020., ~month=1., ~date=31., ())
    let date3 = Js.Date.makeWithYMD(~year=2019., ~month=2., ~date=21., ())
    expect(
      areIntervalsOverlapping({start: date1, end_: date2}, {start: date3, end_: date1}),
    ) |> toBe(false)
  })

  test("getSeconds", () => {
    let date1 = Js.Date.makeWithYMDHMS(
      ~year=2020.,
      ~month=1.,
      ~date=30.,
      ~hours=15.,
      ~minutes=10.,
      ~seconds=25.,
      (),
    )
    expect(getSeconds(date1)) |> toBe(25)
  })

  test("getSecondsf", () => {
    let date1 = Js.Date.makeWithYMDHMS(
      ~year=2020.,
      ~month=1.,
      ~date=30.,
      ~hours=15.,
      ~minutes=10.,
      ~seconds=25.,
      (),
    )

    expect(getSecondsf(date1)) |> toBe(25.0)
  })

  test("setMinutes", () => {
    let date1 = Js.Date.makeWithYMDHMS(
      ~year=2020.,
      ~month=1.,
      ~date=30.,
      ~hours=15.,
      ~minutes=10.,
      ~seconds=25.,
      (),
    )

    expect(date1->setMinutes(25)->getMinutes) |> toEqual(25)
  })

  test("getHours", () => {
    let date1 = Js.Date.makeWithYMDHMS(
      ~year=2020.,
      ~month=1.,
      ~date=30.,
      ~hours=15.,
      ~minutes=10.,
      ~seconds=25.,
      (),
    )
    expect(date1->getHours) |> toEqual(15)
  })
  test("getDate", () => {
    let date1 = Js.Date.makeWithYMDHMS(
      ~year=2020.,
      ~month=4.,
      ~date=1.,
      ~hours=15.,
      ~minutes=10.,
      ~seconds=25.,
      (),
    )
    expect(date1->getDate) |> toBe(1)
  })

  test("getDay", () => {
    let date1 = Js.Date.makeWithYMDHMS(
      ~year=2021.,
      ~month=4.,
      ~date=8.,
      ~hours=2.,
      ~minutes=10.,
      ~seconds=25.,
      (),
    )
    // the day of week, 0 represents Sunday
    expect(date1->getDay) |> toBe(6)
  })

  test("getISODay", () => {
    let date1 = Js.Date.makeWithYMDHMS(
      ~year=2021.,
      ~month=4.,
      ~date=8.,
      ~hours=2.,
      ~minutes=10.,
      ~seconds=25.,
      (),
    )
    // the day of week, 0 represents Sunday
    expect(date1->getISODay) |> toBe(6)
  })

  test("isFriday", () => {
    let date1 = Js.Date.makeWithYMDHMS(
      ~year=2021.,
      ~month=3.,
      ~date=9.,
      ~hours=2.,
      ~minutes=10.,
      ~seconds=25.,
      (),
    )

    // the day of week, 0 represents Sunday
    expect(date1->isFriday) |> toBe(true)
  })
  test("differenceInCalendarWeeksOptf", () => {
    let date1 = Js.Date.makeWithYMDHMS(
      ~year=2021.,
      ~month=3.,
      ~date=9.,
      ~hours=2.,
      ~minutes=10.,
      ~seconds=25.,
      (),
    )
    let date2 = Js.Date.makeWithYMDHMS(
      ~year=2022.,
      ~month=3.,
      ~date=9.,
      ~hours=2.,
      ~minutes=10.,
      ~seconds=25.,
      (),
    )
    // 1 year = 52 weeks
    expect(
      date1->differenceInCalendarWeeksOptf(date2, {locale: Some(ko), weekStartsOn: Some(1)}),
    ) |> toBe(-52.)
  })
})
