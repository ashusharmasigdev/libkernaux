mod ntoa;

pub use ntoa::*;

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_ntoa() {
        assert_eq!(utoa10(123), "123");
    }
}
