#![no_std]

#[cfg(test)]
extern crate std;

pub mod assert;
pub mod ntoa;

pub use assert::*;
pub use ntoa::{MAX_PREFIX_LEN as NTOA_MAX_PREFIX_LEN, *};
